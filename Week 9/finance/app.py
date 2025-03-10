import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd
from datetime import datetime

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    portfolio = db.execute("SELECT * FROM portfolios JOIN symbols ON id == symbol_id WHERE user_id == ? ORDER BY date DESC;", session["user_id"])
    cash = db.execute("SELECT cash FROM users WHERE id == ?;", session["user_id"])[0]["cash"]
    return render_template("index.html", portfolio=portfolio, cash=usd(cash))


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "GET":
        return render_template("buy.html")
    else:
        symbol = request.form.get("symbol")
        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("TODO")
        json = lookup(symbol)
        if not json:
            return apology("TODO")
        price = json["price"]
        if not shares > 0:
            return apology("TODO")
        cash = db.execute("SELECT cash FROM users WHERE id == ?;", session["user_id"])[0]["cash"]
        total_price = shares * price
        if cash < total_price:
            return apology("TODO")
        query = db.execute("SELECT * FROM symbols WHERE symbol == ?", symbol)
        if len(query) == 0:
            db.execute("INSERT INTO symbols (symbol) VALUES(?)", symbol)
        date = str(datetime.now())[:-7]
        db.execute("INSERT INTO portfolios (user_id, symbol_id, shares, price, date) SELECT ?, (SELECT id FROM symbols WHERE symbol = ?), ?, ?, ?;", session["user_id"], symbol, shares, price, date)
        db.execute("INSERT INTO log (user_id, symbol_id, shares, price, date) SELECT ?, (SELECT id FROM symbols WHERE symbol = ?), ?, ?, ?;", session["user_id"], symbol, shares, price, date)
        db.execute("UPDATE users SET cash = ? WHERE id = ?", cash - total_price, session["user_id"])
        return redirect("/")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    log = db.execute("SELECT * FROM log JOIN symbols ON id == symbol_id WHERE user_id == ? ORDER BY date DESC;", session["user_id"])
    print(log)
    return render_template("history.html", log=log)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]
        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        return render_template("quote.html")
    if request.method == "POST":
        symbol = request.form.get("symbol")
        json = lookup(symbol)
        if not json:
            return apology("TODO")
        return render_template("quoted.html", json=json)

@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")
    else:
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        previous = db.execute("SELECT * FROM users WHERE username == ?", username)
        if not username or len(previous) != 0:
            return apology("TODO")
        if not password:
            return apology("TODO")
        if not confirmation or password != confirmation:
            return apology("TODO")
        hashed_password = generate_password_hash(password)
        db.execute("INSERT INTO users (username, hash, cash) VALUES (?, ?, 10000)", username, hashed_password)
        return redirect("/")

@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    portfolio = db.execute("SELECT * FROM portfolios JOIN symbols ON id == symbol_id WHERE user_id == ?;", session["user_id"])
    if request.method == "GET":
        return render_template("sell.html", portfolio=portfolio)
    else:
        symbol = request.form.get("symbol")
        shares = int(request.form.get("shares"))
        cash = db.execute("SELECT cash FROM users WHERE id == ?;", session["user_id"])[0]["cash"]
        json = lookup(symbol)
        if not json:
            apology("TODO")
        price = json["price"]
        if not symbol in portfolio:
            apology("TODO")
        for row in portfolio:
            if row["symbol"] == symbol and row["shares"] >= shares:
                db.execute("UPDATE users SET cash = ? WHERE id = ?", cash + shares * price , session["user_id"])
                if row["shares"] == shares:
                    date = str(datetime.now())[:-7]
                    db.execute("INSERT INTO log (user_id, symbol_id, shares, price, date) SELECT ?, (SELECT id FROM symbols WHERE symbol = ?), ?, (SELECT price FROM portfolios WHERE user_id == ? AND symbol_id == (SELECT id FROM symbols WHERE symbol == ?)), ?;", session["user_id"], symbol, 0, session["user_id"], symbol, date)
                    db.execute("DELETE FROM portfolios WHERE user_id == ? AND symbol_id == (SELECT id FROM symbols WHERE symbol == ?);", session["user_id"], symbol)
                else:
                    date = str(datetime.now())[:-7]
                    db.execute("UPDATE portfolios SET shares = ?, date = ? WHERE user_id == ? AND symbol_id == (SELECT id FROM symbols WHERE symbol == ?)", row["shares"] - shares, date, session["user_id"], symbol)
                    db.execute("INSERT INTO log (user_id, symbol_id, shares, price, date) SELECT ?, (SELECT id FROM symbols WHERE symbol = ?), ?, (SELECT price FROM portfolios WHERE user_id == ? AND symbol_id == (SELECT id FROM symbols WHERE symbol == ?)), ?;", session["user_id"], symbol, row["shares"] - shares, session["user_id"], symbol, date)
                return redirect("/")
        return apology("TODO")