--                      ### CREATE TABLE COMMAND AND SPECIFING DATATYPES AND CONSTRIANS
        -- #SYNTAX : -
        --          CREATE TABLE <TABLENAME> (
        --              ATTRIBUTE1 DATATYPE1 CONSTRIAN1,
        --              ATTRIBUTE2 DATATYPE2 CONSTRIAN2,
        --                  :           :       :
        --                  :           :       :
        --              ATTRIBUTEn DATATYPEn CONSTRIANN
        --          );


CREATE TABLE DPT(
     DPTNAME VARCHAR(20) NOT NULL,
     DPTNO INT(3) PRIMARY KEY,
     DPTSTRDATE DATE DEFAULT("2020-1-10"),
     MGRSSN INT(6));
-- DESC DPT
-- +------------+-------------+------+-----+------------+-------+
-- | Field      | Type        | Null | Key | Default    | Extra |
-- +------------+-------------+------+-----+------------+-------+
-- | DPTNAME    | varchar(20) | NO   |     | NULL       |       |
-- | DPTNO      | int(3)      | NO   | PRI | NULL       |       |
-- | DPTSTRDATE | date        | YES  |     | 2020-01-10 |       |
-- | MGRSNN     | int(6)      | YES  |     | NULL       |       |
-- +------------+-------------+------+-----+------------+-------+


CREATE TABLE EMP_DEMO(
     FNAME VARCHAR(20) NOT NULL,
     MINITIAL CHAR(1),
     LNAME VARCHAR(20) NOT NULL,
     SSN INT(6) PRIMARY KEY,
     DOB DATE,
     SALARY DECIMAL(10,2) CHECK (SALARY BETWEEN 00.00 AND 1000000.00),
     DPTNO INT(3) NOT NULL,
     SEX CHAR(1) NOT NULL,
     ADDRESS VARCHAR(25) NOT NULL,
     FOREIGN KEY (DPTNO) REFERENCES DPT (DPTNO)
     );
-- DESC EMP
-- +----------+---------------+------+-----+---------+-------+
-- | Field    | Type          | Null | Key | Default | Extra |
-- +----------+---------------+------+-----+---------+-------+
-- | FNAME    | varchar(20)   | NO   |     | NULL    |       |
-- | MINITIAL | char(1)       | YES  |     | NULL    |       |
-- | LNAME    | varchar(20)   | NO   |     | NULL    |       |
-- | SNN      | int(6)        | NO   | PRI | NULL    |       |
-- | DOB      | date          | YES  |     | NULL    |       |
-- | SALARY   | decimal(10,2) | YES  |     | NULL    |       |
-- | DPTNO    | int(3)        | NO   | MUL | NULL    |       |
-- | SEX      | char(1)       | NO   |     | NULL    |       |
-- | ADDRESS  | varchar(25)   | NO   |     | NULL    |       |
-- +----------+---------------+------+-----+---------+-------+

 CREATE TABLE DPTLOC(
     DPTNO INT(3),
     DPTLOC VARCHAR(15),
     PRIMARY KEY(DPTNO,DPTLOC),
     FOREIGN KEY(DPTNO) REFERENCES DPT (DPTNO)
    );
-- DESC DPTLOC
-- +--------+-------------+------+-----+---------+-------+
-- | Field  | Type        | Null | Key | Default | Extra |
-- +--------+-------------+------+-----+---------+-------+
-- | DPTNO  | int(3)      | NO   | PRI | NULL    |       |
-- | DPTLOC | varchar(15) | NO   | PRI | NULL    |       |
-- +--------+-------------+------+-----+---------+-------+

CREATE TABLE PRJ(
     PNAME VARCHAR(20) NOT NULL,
     PNO INT(5) PRIMARY KEY,
     CDPTNO INT(3) NOT NULL,
     PLOC VARCHAR(20),
     FOREIGN KEY(CDPTNO) REFERENCES DPT(DPTNO)
     );
-- DESC PRJ
-- +--------+-------------+------+-----+---------+-------+
-- | Field  | Type        | Null | Key | Default | Extra |
-- +--------+-------------+------+-----+---------+-------+
-- | PNAME  | varchar(20) | NO   |     | NULL    |       |
-- | PNO    | int(5)      | NO   | PRI | NULL    |       |
-- | CDPTNO | int(3)      | NO   | MUL | NULL    |       |
-- | PLOC   | varchar(20) | YES  |     | NULL    |       |
-- +--------+-------------+------+-----+---------+-------+

CREATE TABLE WRKON(
     PNO INT(5) NOT NULL,
     SSN INT(6) NOT NULL,
     HOURS DECIMAL(4,2) NOT NULL,     
     FOREIGN KEY (PNO) REFERENCES PRJ (PNO),
     FOREIGN KEY (SSN) REFERENCES EMP (SSN)
     );
--  DESC WRKON;
-- +-------+--------------+------+-----+---------+-------+
-- | Field | Type         | Null | Key | Default | Extra |
-- +-------+--------------+------+-----+---------+-------+
-- | PNO   | int(5)       | NO   | MUL | NULL    |       |
-- | SSN   | int(6)       | NO   | MUL | NULL    |       |
-- | HOURS | decimal(4,2) | NO   |     | NULL    |       |
-- +-------+--------------+------+-----+---------+-------+

CREATE TABLE DEP(
     DEPNAME VARCHAR(20) NOT NULL,
     SSN INT(6) NOT NULL,
     RELATION VARCHAR(15) NOT NULL,
     DOB DATE,
     SEX CHAR(1),
     FOREIGN KEY (SSN) REFERENCES EMP (SSN)
     );

--  DESC DEP;
-- +----------+-------------+------+-----+---------+-------+
-- | Field    | Type        | Null | Key | Default | Extra |
-- +----------+-------------+------+-----+---------+-------+
-- | DEPNAME  | varchar(20) | NO   |     | NULL    |       |
-- | SSN      | int(6)      | NO   | MUL | NULL    |       |
-- | RELATION | varchar(15) | NO   |     | NULL    |       |
-- | DOB      | date        | YES  |     | NULL    |       |
-- | SEX      | char(1)     | YES  |     | NULL    |       |
-- +----------+-------------+------+-----+---------+-------+


--              #INSERT VALUES AND SELECT COMMAND TO DISPLAY TABLE
 INSERT INTO DPT VALUES
     ("CS","101","2020-1-10",101001),
     ("EC","102","2020-3-12",102001),
     ("ME","103","2020-2-12",103001);
--  SELECT * FROM DPT;
-- +---------+-------+------------+--------+
-- | DPTNAME | DPTNO | DPTSTRDATE | MGRSSN |
-- +---------+-------+------------+--------+
-- | CS      |   101 | 2020-01-10 | 101001 |
-- | EC      |   102 | 2020-03-12 | 102001 |
-- | ME      |   103 | 2020-02-12 | 103001 |
-- +---------+-------+------------+--------+

 INSERT INTO EMP VALUES
    ("SURAJ","S","SAVANT",101001,"2002-6-10",80000.00,101,"M","SHINAL"),
    ("POORVI","S","PATIL",102001,"2003-3-10",80000.00,102,"F","ATHANI"),
    ("RAJU","L","KATTI",103001,"2003-3-10",70000.00,103,"M","SHANTINAGAR"),
    ("VIJAY","A","MANE",101002,"1999-4-29",72000.00,101,"M","SHINAL"),
    ("POOJA","A","PATIL",101003,"2003-4-29",65000.00,101,"F","SHINAL"),
    ("RAJU","A","JADHAV",102002,"2000-4-29",33000.00,102,"M","MOLE"),
    ("RADHA","A","KADAM",103002,"2000-4-29",34000.00,103,"F","AINAPUR"),
    ;
--     SELECT * FROM EMP;
-- +---------+----------+--------+--------+------------+----------+-------+-----+-------------+
-- | FNAME   | MINITIAL | LNAME  | SSN    | DOB        | SALARY   | DPTNO | SEX | ADDRESS     |
-- +---------+----------+--------+--------+------------+----------+-------+-----+-------------+
-- | SURAJ   | S        | SAVANT | 101001 | 2002-06-10 | 80000.00 |   101 | M   | SHINAL      |
-- | VIJAY   | A        | MANE   | 101002 | 1999-04-29 | 72000.00 |   101 | M   | SHINAL      |
-- | POOJA   | A        | PATIL  | 101003 | 2003-04-29 | 65000.00 |   101 | F   | SHINAL      |
-- | POORVI  | S        | PATIL  | 102001 | 2003-03-10 | 80000.00 |   102 | F   | ATHANI      |
-- | RAJU    | A        | JADHAV | 102002 | 2000-04-29 | 33000.00 |   102 | M   | MOLE        |
-- | RAJU    | L        | KATTI  | 103001 | 2003-03-10 | 70000.00 |   103 | M   | SHANTINAGAR |
-- | RADHA   | A        | KADAM  | 103002 | 2000-04-29 | 34000.00 |   103 | F   | AINAPUR     |
-- +---------+----------+--------+--------+------------+----------+-------+-----+-------------+

INSERT INTO DPTLOC VALUES
     (101,"SHANTINAGAR"),
     (101,"ATHANI"),
     (102,"PUNE"),
     (103,"PUNE");
--   SELECT * FROM DPTLOC;
-- +-------+-------------+
-- | DPTNO | DPTLOC      |
-- +-------+-------------+
-- |   101 | ATHANI      |
-- |   101 | SHANTINAGAR |
-- |   102 | PUNE        |
-- |   103 | PUNE        |
-- +-------+-------------+

INSERT INTO PRJ VALUES
     ("GEOLATION API",10101,101,"SHANTINAGAR"),
     ("REMOTE SENSING",10201,102,"PUNE"),
     ("WEB APP",10102,101,"ATHANI")
     ;    
--  SELECT * FROM PRJ;
-- +----------------+-------+--------+-------------+
-- | PNAME          | PNO   | CDPTNO | PLOC        |
-- +----------------+-------+--------+-------------+
-- | GEOLATION API  | 10101 |    101 | SHANTINAGAR |
-- | WEB APP        | 10102 |    101 | ATHANI      |
-- | REMOTE SENSING | 10201 |    102 | PUNE        |
-- +----------------+-------+--------+-------------+

 INSERT INTO WRKON VALUES
     (10101,101002,4.5),
     (10101,101001,3.4),
     (10102,101001,4.5),
     (10201,102001,4.6),
     (10201,102002,3.4)
     ;
--  SELECT * FROM WRKON;
-- +-------+--------+-------+
-- | PNO   | SSN    | HOURS |
-- +-------+--------+-------+
-- | 10101 | 101002 |  4.50 |
-- | 10101 | 101001 |  3.40 |
-- | 10102 | 101001 |  4.50 |
-- | 10201 | 102001 |  4.60 |
-- | 10201 | 102002 |  3.40 |
-- +-------+--------+-------+

INSERT INTO DEP VALUES
     ("SHUBHAM",101001,"BROTHER","2005-4-16","M"),
     ("RANI",101002,"WIFE","2000-4-29","F"),
     ("NAVEEN",102001,"HUSBAND","1999-2-12","M")
     ;
-- SELECT * FROM DEP;
-- +---------+--------+----------+------------+------+
-- | DEPNAME | SSN    | RELATION | DOB        | SEX  |
-- +---------+--------+----------+------------+------+
-- | SHUBHAM | 101001 | BROTHER  | 2005-04-16 | M    |
-- | RANI    | 101002 | WIFE     | 2000-04-29 | F    |
-- | NAVEEN  | 102001 | HUSBAND  | 1999-02-12 | M    |
-- +---------+--------+----------+------------+------+

--          #SELECT COMMAND QUERIES
                    SELECT FNAME, LNAME, DOB FROM EMP;
                         -- +--------+--------+------------+
                         -- | FNAME  | LNAME  | DOB        |
                         -- +--------+--------+------------+
                         -- | SURAJ  | SAVANT | 2002-06-10 |
                         -- | VIJAY  | MANE   | 1999-04-29 |
                         -- | POOJA  | PATIL  | 2003-04-29 |
                         -- | POORVI | PATIL  | 2003-03-10 |
                         -- | RAJU   | JADHAV | 2000-04-29 |
                         -- | RAJU   | KATTI  | 2003-03-10 |
                         -- | RADHA  | KADAM  | 2000-04-29 |
                         -- +--------+--------+------------+

                    SELECT DPTNAME FROM DPT;
                         -- +---------+
                         -- | DPTNAME |
                         -- +---------+
                         -- | CS      |
                         -- | EC      |
                         -- | ME      |
                         -- +---------+

--                  #CONDITIONAL RETRIVAL USING WHERE CLAUSE


--                  #SELECT FROM MULTIPLE TABLES BY JOINING PRIMARY KEY AND FOREIGN KEY 
SELECT FNAME AS EMPNAME,DEPNAME, DEP.SSN, DEP.DOB AS DEPDOB, RELATION AS RELATIONSHIP
     FROM EMP, DEP
     WHERE EMP.SSN = DEP.SSN;
-- +---------+---------+--------+------------+--------------+
-- | EMPNAME | DEPNAME | SSN    | DEPDOB     | RELATIONSHIP |
-- +---------+---------+--------+------------+--------------+
-- | SURAJ   | SHUBHAM | 101001 | 2005-04-16 | BROTHER      |
-- | VIJAY   | RANI    | 101002 | 2000-04-29 | WIFE         |
-- | POORVI  | NAVEEN  | 102001 | 1999-02-12 | HUSBAND      |
-- +---------+---------+--------+------------+--------------+

SELECT DPTNAME, DPTLOC, DPT.DPTNO
     FROM DPT, DPTLOC
     WHERE DPT.DPTNO = DPTLOC.DPTNO AND DPTLOC = "PUNE";
-- +---------+--------+-------+
-- | DPTNAME | DPTLOC | DPTNO |
-- +---------+--------+-------+
-- | EC      | PUNE   |   102 |
-- | ME      | PUNE   |   103 |
-- +---------+--------+-------+

--   #NESTED QUERIES
 
 select * from emp where not exists ((select ssn from dep where dep.ssn = emp.ssn));

-- +-------+----------+--------+--------+------------+----------+-------+-----+-------------+
-- | FNAME | MINITIAL | LNAME  | SSN    | DOB        | SALARY   | DPTNO | SEX | ADDRESS     |
-- +-------+----------+--------+--------+------------+----------+-------+-----+-------------+
-- | POOJA | A        | PATIL  | 101003 | 2003-04-29 | 84000.00 |   101 | F   | SHINAL      |
-- | RAJU  | A        | JADHAV | 102002 | 2000-04-29 | 75000.00 |   102 | M   | MOLE        |
-- | RAJU  | L        | KATTI  | 103001 | 2003-03-10 | 58000.00 |   103 | M   | SHANTINAGAR |
-- | RADHA | A        | KADAM  | 103002 | 2000-04-29 | 47000.00 |   103 | F   | AINAPUR     |
-- +-------+----------+--------+--------+------------+----------+-------+-----+-------------+

 SELECT DPTNAME, DPT.DPTNO, SUM(SALARY) TOTAL, MAX(SALARY), MIN(SALARY)
     FROM EMP, DPT
     WHERE EMP.DPTNO = DPT.DPTNO
     GROUP BY DPT.DPTNO;

     CREATE TABLE EMP(
     FNAME VARCHAR(20) NOT NULL,
     MINITIAL CHAR(1),
     LNAME VARCHAR(20),
     SSN INT(6) PRIMARY KEY
     );

     ALTER TABLE EMP ADD(
     DPTNO INT(3) NOT NULL,
     FOREIGN KEY(DPTNO) REFERENCES DPT(DPTNO)
     );
 
--  SELECT LOWER(DPTNAME),E.DPTNO,FNAME,MGRSSN,MAX(SALARY) AS MAXSAL,MIN(SALARY) AS MINSAL,AVG(SALARY) AS AVGSAL,COUNT(SSN) AS ENPNO, DPTSTRDATE
--      FROM EMP E, DPT D
--      WHERE E.DPTNO = D.DPTNO
--      GROUP BY E.DPTNO
--      ORDER BY SALARY;

    ALTER TABLE EMP ADD(
     DPTNO INT(3) NOT NULL,
     FOREIGN KEY(DPTNO) REFERENCES DPT(DPTNO)
     ); 

      CREATE TABLE DPTLOC(
     DPTNO INT(3),
     DPTLOC VARCHAR(20),
     PRIMARY KEY(DPTNO,DPTLOC)
      );

      SELECT PNAME,PRJ.PNO,COUNT(*),CDPTNO
     FROM PRJ,WRKON, DPT
     WHERE PRJ.PNO = WRKON.PNO,DPT.DPTNO = CDPTNO
     GROUP BY PRJ.PNO;

      SELECT PNAME, P.PNO, DPTNO, DPTNAME, PLOC, COUNT(DISTINCT SSN)
     FROM PRJ P, WRKON W, DPT D
     WHERE D.DPTNO = P.CDPTNO AND P.PNO = W.PNO
     GROUP BY P.PNO;

     
