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

SET default_tablespace = '';

SET default_with_oids = false;

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
-- Name: groups; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE groups (
    group_id integer NOT NULL,
    group_name character varying NOT NULL
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
    group_id integer NOT NULL
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
-- Data for Name: disciplines; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY disciplines (discipline_id, discipline_name, teacher_id) FROM stdin;
1	Бд и ЭС	1
\.


--
-- Data for Name: groups; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY groups (group_id, group_name) FROM stdin;
1	К7-361
2	К5-361
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

COPY students (student_id, student_sname, student_fname, student_mname, group_id) FROM stdin;
1	Букарев	Павел	Владимирович	1
2	Воронин	Дмитрий	Леонидович	1
3	Данилин	Егор	Дмитриевич	1
4	Игин	Алексей	Георгиевич	1
5	Ильясова	Нина	Альбертовна	1
6	Лукьяненко	Леонид	Владимирович	1
7	Нарбутович	Анна	Евгеньевна	1
8	Персиянов	Алексей	Максимович	1
9	Фадеева	Анна	Юрьевна	1
10	Щербаков	Павел	Александрович	1
\.


--
-- Data for Name: teachers; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY teachers (teacher_id, teacher_fname, teacher_mname, teacher_sname) FROM stdin;
1	Сергей	Константинович	Муравьёв
\.


--
-- Name: discipline_id; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY disciplines
    ADD CONSTRAINT discipline_id PRIMARY KEY (discipline_id);


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
-- Name: disciplines_groups_disciplines_fk; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY groups_disciplines
    ADD CONSTRAINT disciplines_groups_disciplines_fk FOREIGN KEY (discipline_id) REFERENCES disciplines(discipline_id);


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

