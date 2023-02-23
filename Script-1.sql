//Teacher reviews:

CREATE TABLE teachers (
    student_id INT,
    teacher_id SERIAL PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    subjects_taught VARCHAR(100) NOT NULL,
    school VARCHAR(100) NOT null
    
);
ALTER TABLE teachers 
ALTER COLUMN school SET DEFAULT 'Institute of Business Administration, Khi';
ALTER TABLE teachers 
ADD COLUMN department VARCHAR(100);

CREATE TABLE students (
    erp_id integer PRIMARY KEY,
    username VARCHAR(50) NOT NULL,
    email VARCHAR(100) UNIQUE NOT NULL,
    name varchar(100) NOT NULL,
    school varchar(100) NOT null ,
    password VARCHAR(100) NOT NULL
);

ALTER TABLE students 
ALTER COLUMN school SET DEFAULT 'Institute of Business Administration, Khi';

ALTER TABLE students 
ADD COLUMN gender VARCHAR(10) CHECK (gender IN ('male', 'female'));


CREATE TABLE reviews (
    review_id SERIAL PRIMARY KEY,
    teacher_id INTEGER REFERENCES teachers (teacher_id),
    student_id INTEGER REFERENCES students (erp_id),
    overall_rating INTEGER NOT NULL CHECK (overall_rating BETWEEN 1 AND 5),
    review_text TEXT NOT NULL,
    category VARCHAR(100) NOT NULL,
    date_written DATE NOT NULL
);

CREATE TABLE categories (
    category_id SERIAL PRIMARY KEY,
    category_name VARCHAR(100) NOT NULL,
    category_rating INTEGER NOT NULL CHECK (category_rating BETWEEN 1 AND 5),
    teacher_id INTEGER REFERENCES teachers (teacher_id)
);



//Resource tab:


CREATE TABLE resources (
    resource_id SERIAL PRIMARY KEY,
    student_id INTEGER,
    name VARCHAR(100) NOT NULL,
    category VARCHAR(50) NOT NULL,
    file BYTEA NOT NULL,
    price INTEGER NOT NULL,
    security VARCHAR(50) NOT NULL,
    CONSTRAINT fk_user FOREIGN KEY (student_id) REFERENCES students(erp_id)
);

//University profile



CREATE TABLE profiles (
profile_id SERIAL PRIMARY KEY,
erp_id INTEGER UNIQUE references students(erp_id),
skills TEXT[],
hobbies TEXT[],
interests TEXT[]
);


//Upcoming Events 


CREATE TABLE events (
event_id SERIAL PRIMARY KEY,
name VARCHAR(100) NOT NULL,
date TIMESTAMP NOT NULL,
location VARCHAR(100) NOT NULL,
description TEXT NOT NULL
);

CREATE TABLE rsvps (
rsvp_id SERIAL PRIMARY KEY,
event_id INTEGER REFERENCES events (event_id),
student_id INTEGER REFERENCES students (erp_id),
CONSTRAINT unique_rsvp UNIQUE (event_id, student_id)
);


//Student Study Sessions

CREATE TABLE topics (
topic_id SERIAL PRIMARY KEY,
name VARCHAR(100) NOT NULL
);

CREATE TABLE group_study_sessions (
session_id SERIAL PRIMARY KEY,
name VARCHAR(100) NOT NULL,
date_time TIMESTAMP NOT NULL,
num_participants INTEGER NOT NULL,
creator_id INTEGER REFERENCES students (erp_id) NOT NULL
);
ALTER TABLE group_study_sessions 
ADD COLUMN gender_preference VARCHAR(10) CHECK (gender_preference IN ('male', 'female', 'no preference'));
ALTER TABLE group_study_sessions 
ADD COLUMN duration INTERVAL;


CREATE TABLE group_study_sessions_topics (
session_id INTEGER REFERENCES group_study_sessions (session_id),
topic_id INTEGER REFERENCES topics (topic_id),
PRIMARY KEY (session_id, topic_id)
);


