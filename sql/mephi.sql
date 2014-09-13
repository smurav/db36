--
-- PostgreSQL database dump
--

SET statement_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = off;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET escape_string_warning = off;

--
-- Name: plpgsql; Type: PROCEDURAL LANGUAGE; Schema: -; Owner: postgres
--

CREATE OR REPLACE PROCEDURAL LANGUAGE plpgsql;


ALTER PROCEDURAL LANGUAGE plpgsql OWNER TO postgres;

SET search_path = public, pg_catalog;

--
-- Name: composite_name; Type: TYPE; Schema: public; Owner: postgres
--

CREATE TYPE composite_name AS (
	fname text,
	mname text,
	sname text
);


ALTER TYPE public.composite_name OWNER TO postgres;

--
-- Name: group_name; Type: DOMAIN; Schema: public; Owner: postgres
--

CREATE DOMAIN group_name AS text
	CONSTRAINT group_name_check CHECK ((VALUE ~ '[АКТФ][1-9]0?-[1-3][0-9][1-4]'::text));


ALTER DOMAIN public.group_name OWNER TO postgres;

--
-- Name: get_faculty_by_group_id(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION get_faculty_by_group_id(integer) RETURNS character
    LANGUAGE sql
    AS $_$
SELECT departments.faculty_id from departments join groups on departments.department_id = groups.department_id where groups.group_id=$1;
$_$;


ALTER FUNCTION public.get_faculty_by_group_id(integer) OWNER TO postgres;

--
-- Name: get_group_name_by_id(integer); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION get_group_name_by_id(integer) RETURNS text
    LANGUAGE sql
    AS $_$
SELECT cast(departments.faculty_id as text) || cast(date_part('year',age(groups.group_entering_date)) * 2 + case when date_part('month',current_date) > 6 then 1 else 0 end as text) || '-' || cast(departments.department_id as text) || cast(groups.group_number as text) from departments join groups on departments.department_id = groups.department_id where groups.group_id=$1;
$_$;


ALTER FUNCTION public.get_group_name_by_id(integer) OWNER TO postgres;

--
-- Name: get_semester(date); Type: FUNCTION; Schema: public; Owner: postgres
--

CREATE FUNCTION get_semester(date) RETURNS integer
    LANGUAGE c STRICT
    AS '/var/lib/pgsql/libdb36', 'get_semester';


ALTER FUNCTION public.get_semester(date) OWNER TO postgres;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- Name: departments; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE departments (
    department_id integer NOT NULL,
    department_name character varying(40) NOT NULL,
    faculty_id character(1)
);


ALTER TABLE public.departments OWNER TO postgres;

--
-- Name: disciplines; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE disciplines (
    discipline_id integer NOT NULL,
    discipline_name character varying NOT NULL,
    teacher_id character varying NOT NULL
);


ALTER TABLE public.disciplines OWNER TO postgres;

--
-- Name: faculties; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE faculties (
    faculty_id character(1) NOT NULL,
    faculty_name character varying(20) NOT NULL
);


ALTER TABLE public.faculties OWNER TO postgres;

--
-- Name: groups; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE groups (
    group_id integer NOT NULL,
    department_id integer,
    group_number integer,
    group_entering_date date
);


ALTER TABLE public.groups OWNER TO postgres;

--
-- Name: groups_disciplines; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE groups_disciplines (
    discipline_id integer NOT NULL,
    group_id integer NOT NULL
);


ALTER TABLE public.groups_disciplines OWNER TO postgres;

--
-- Name: groups_students; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE groups_students (
    student_id integer NOT NULL,
    group_id integer NOT NULL
);


ALTER TABLE public.groups_students OWNER TO postgres;

--
-- Name: students; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE students (
    student_id integer NOT NULL,
    student_sname character varying NOT NULL,
    student_fname character varying NOT NULL,
    student_mname character varying NOT NULL,
    group_id integer NOT NULL,
    student_composite_name composite_name
);


ALTER TABLE public.students OWNER TO postgres;

--
-- Name: TABLE students; Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON TABLE students IS 'Таблица студентов МИФИ';


--
-- Name: teachers; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE teachers (
    teacher_id character varying NOT NULL,
    teacher_fname character varying NOT NULL,
    teacher_mname character varying NOT NULL,
    teacher_sname character varying NOT NULL
);


ALTER TABLE public.teachers OWNER TO postgres;

--
-- Data for Name: departments; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY departments (department_id, department_name, faculty_id) FROM stdin;
36	Информационные системы и технологии	К
22	Кибернетика	К
33	Математическое обеспечение систем	К
\.


--
-- Data for Name: disciplines; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY disciplines (discipline_id, discipline_name, teacher_id) FROM stdin;
1	Бд и ЭС	1
\.


--
-- Data for Name: faculties; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY faculties (faculty_id, faculty_name) FROM stdin;
К	Кибернетика
А	Автоматика
Т	Теоретическая физика
Ф	Физико-технический
\.


--
-- Data for Name: groups; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY groups (group_id, department_id, group_number, group_entering_date) FROM stdin;
1	36	1	2009-09-01
2	36	1	2010-09-01
\.


--
-- Data for Name: groups_disciplines; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY groups_disciplines (discipline_id, group_id) FROM stdin;
1	1
\.


--
-- Data for Name: groups_students; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY groups_students (student_id, group_id) FROM stdin;
\.


--
-- Data for Name: students; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY students (student_id, student_sname, student_fname, student_mname, group_id, student_composite_name) FROM stdin;
2	Воронин	Дмитрий	Леонидович	1	\N
3	Данилин	Егор	Дмитриевич	1	\N
4	Игин	Алексей	Георгиевич	1	\N
5	Ильясова	Нина	Альбертовна	1	\N
6	Лукьяненко	Леонид	Владимирович	1	\N
7	Нарбутович	Анна	Евгеньевна	1	\N
8	Персиянов	Алексей	Максимович	1	\N
9	Фадеева	Анна	Юрьевна	1	\N
10	Щербаков	Павел	Александрович	1	\N
1	Букарев	Павел	Владимирович	1	(Букарев,Павел,Владимирович)
\.


--
-- Data for Name: teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY teachers (teacher_id, teacher_fname, teacher_mname, teacher_sname) FROM stdin;
1	Сергей	Константинович	Муравьёв
\.


--
-- Name: departments_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY departments
    ADD CONSTRAINT departments_pkey PRIMARY KEY (department_id);


--
-- Name: discipline_id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY disciplines
    ADD CONSTRAINT discipline_id PRIMARY KEY (discipline_id);


--
-- Name: faculty_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY faculties
    ADD CONSTRAINT faculty_pkey PRIMARY KEY (faculty_id);


--
-- Name: group_id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY groups
    ADD CONSTRAINT group_id PRIMARY KEY (group_id);


--
-- Name: groups_disciplines_pk; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY groups_disciplines
    ADD CONSTRAINT groups_disciplines_pk PRIMARY KEY (discipline_id, group_id);


--
-- Name: id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY groups_students
    ADD CONSTRAINT id PRIMARY KEY (student_id, group_id);


--
-- Name: student_id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY students
    ADD CONSTRAINT student_id PRIMARY KEY (student_id);


--
-- Name: teacher_id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY teachers
    ADD CONSTRAINT teacher_id PRIMARY KEY (teacher_id);


--
-- Name: departments_faculty_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY departments
    ADD CONSTRAINT departments_faculty_fk FOREIGN KEY (faculty_id) REFERENCES faculties(faculty_id);


--
-- Name: disciplines_groups_disciplines_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY groups_disciplines
    ADD CONSTRAINT disciplines_groups_disciplines_fk FOREIGN KEY (discipline_id) REFERENCES disciplines(discipline_id);


--
-- Name: groups_department_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY groups
    ADD CONSTRAINT groups_department_fk FOREIGN KEY (department_id) REFERENCES departments(department_id);


--
-- Name: groups_groups_disciplines_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY groups_disciplines
    ADD CONSTRAINT groups_groups_disciplines_fk FOREIGN KEY (group_id) REFERENCES groups(group_id);


--
-- Name: groups_students_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY students
    ADD CONSTRAINT groups_students_fk FOREIGN KEY (group_id) REFERENCES groups(group_id);


--
-- Name: teachers_disciplines_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY disciplines
    ADD CONSTRAINT teachers_disciplines_fk FOREIGN KEY (teacher_id) REFERENCES teachers(teacher_id);


--
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


--
-- PostgreSQL database dump complete
--

