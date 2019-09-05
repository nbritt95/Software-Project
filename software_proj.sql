-- MySQL dump 10.13  Distrib 8.0.16, for Win64 (x86_64)
--
-- Host: localhost    Database: software_proj
-- ------------------------------------------------------
-- Server version	8.0.16

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `admin_table`
--

DROP TABLE IF EXISTS `admin_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `admin_table` (
  `Admin_ID` int(11) NOT NULL,
  `First_Name` varchar(30) NOT NULL,
  `Last_Name` varchar(45) NOT NULL,
  `Password` varchar(45) NOT NULL,
  PRIMARY KEY (`Admin_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `admin_table`
--

LOCK TABLES `admin_table` WRITE;
/*!40000 ALTER TABLE `admin_table` DISABLE KEYS */;
INSERT INTO `admin_table` VALUES (200345,'John','Smith','jsmith123');
/*!40000 ALTER TABLE `admin_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `courses_table`
--

DROP TABLE IF EXISTS `courses_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `courses_table` (
  `Course_ID` int(12) NOT NULL,
  `Course_Number` int(11) NOT NULL,
  `Course_Name` varchar(45) NOT NULL,
  `Start_Time` varchar(45) NOT NULL,
  `End_Time` varchar(45) NOT NULL,
  `Course_Days` varchar(45) NOT NULL,
  `Professor_Name` varchar(45) NOT NULL,
  PRIMARY KEY (`Course_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `courses_table`
--

LOCK TABLES `courses_table` WRITE;
/*!40000 ALTER TABLE `courses_table` DISABLE KEYS */;
/*!40000 ALTER TABLE `courses_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `grades_table`
--

DROP TABLE IF EXISTS `grades_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `grades_table` (
  `Student_ID` int(12) NOT NULL,
  `Course_ID` int(12) NOT NULL,
  `Exam1_Grade` int(11) DEFAULT NULL,
  `Exam2_Grade` int(11) DEFAULT NULL,
  `Final_Exam_Grade` int(11) DEFAULT NULL,
  `Final_Grade` int(11) DEFAULT NULL,
  PRIMARY KEY (`Student_ID`),
  KEY `Course_ID_idx` (`Course_ID`),
  CONSTRAINT `Course_ID` FOREIGN KEY (`Course_ID`) REFERENCES `courses_table` (`Course_ID`),
  CONSTRAINT `Student_ID` FOREIGN KEY (`Student_ID`) REFERENCES `students_table` (`Student_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `grades_table`
--

LOCK TABLES `grades_table` WRITE;
/*!40000 ALTER TABLE `grades_table` DISABLE KEYS */;
/*!40000 ALTER TABLE `grades_table` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `students_table`
--

DROP TABLE IF EXISTS `students_table`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
 SET character_set_client = utf8mb4 ;
CREATE TABLE `students_table` (
  `Student_ID` int(12) NOT NULL,
  `Password` varchar(45) NOT NULL,
  `First_Name` varchar(45) NOT NULL,
  `Last_Name` varchar(45) NOT NULL,
  PRIMARY KEY (`Student_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `students_table`
--

LOCK TABLES `students_table` WRITE;
/*!40000 ALTER TABLE `students_table` DISABLE KEYS */;
/*!40000 ALTER TABLE `students_table` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2019-09-05 12:38:26
