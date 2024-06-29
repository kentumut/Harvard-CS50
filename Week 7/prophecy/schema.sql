CREATE TABLE students (
    id INTEGER PRIMARY KEY,
    student_name TEXT
);
CREATE TABLE houses (
    house_id INTEGER PRIMARY KEY,
    house_name TEXT,
    head TEXT
);
CREATE TABLE assignment (
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(house_id)
);