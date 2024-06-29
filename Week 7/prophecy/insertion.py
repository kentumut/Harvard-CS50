from cs50 import SQL
import csv

def houseassign(house):
    for iteration in houses:
        if iteration[0] == house:
            return
    houses.append([house, student["head"]])


def getId(houseName):
    houseId = 0
    for i in houses:
        if i[0] == houseName:
            return houseId
        houseId += 1


with open("students.csv", "r") as csvfile:
    file = csv.DictReader(csvfile)
    students = []
    houses = []
    assignment = []

    for student in file:
        house = student["house"]
        stuid = int(student["id"])
        students.append([stuid, student["student_name"]])
        houseassign(house)
        assignment.append([stuid, getId(house)])

db = SQL("sqlite:///students.db")
for i in students:
    db.execute("INSERT INTO students (student_name) VALUES(?);", i[1])
for i in houses:
    house_name = i[0]
    db.execute("INSERT INTO houses (house_id, house_name, head)  VALUES(?, ?, ?);", getId(house_name), i[0], i[1])
for i in assignment:
    db.execute("INSERT INTO assignment (student_id, house_id) VALUES(?, ?);", i[0], i[1])
