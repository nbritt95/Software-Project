-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema software
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema software
-- -----------------------------------------------------
DROP SCHEMA IF EXISTS `software`;
CREATE SCHEMA IF NOT EXISTS `software` DEFAULT CHARACTER SET utf8 ;
USE `software` ;

-- -----------------------------------------------------
-- Table `software`.`students`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `software`.`students` (
  `student_id` INT NOT NULL AUTO_INCREMENT,
  `first_name` VARCHAR(255) NOT NULL,
  `last_name` VARCHAR(255) NOT NULL,
  `pass_code` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`student_id`),
  UNIQUE INDEX `pass_code_UNIQUE` (`pass_code` ASC) VISIBLE)
ENGINE = InnoDB;
INSERT INTO `students` VALUE (1,'NHUNG','HONG','hong123');
INSERT INTO `students`VALUE (2,'AN','NGUYEN','nguyen123');
INSERT INTO `students`VALUE (3,'HIEP','KWAN','kwan123');

-- -----------------------------------------------------
-- Table `software`.`courses`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `software`.`courses` (
  `class_id` INT NOT NULL AUTO_INCREMENT,
  `course_name` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`class_id`),
  UNIQUE INDEX `course_name_UNIQUE` (`course_name` ASC) VISIBLE)
ENGINE = InnoDB;
INSERT INTO courses() VALUE (default,'MATH');
 INSERT INTO courses VALUE (default,'PHYSIC');
INSERT INTO courses VALUE (default,'CHEMISTRY');
INSERT INTO courses VALUE (default,'COMPUTER');
INSERT INTO courses VALUE (default,'HISTORY');
INSERT INTO courses VALUE (default,'ENGLISH');

-- -----------------------------------------------------
-- Table `software`.`enrollments`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `software`.`enrollments` (
  `student_id` INT NOT NULL,
  `class_id` INT NOT NULL,
  `exam_1` INT NULL DEFAULT 0,
  `exam_2` INT NULL DEFAULT 0,
  `final_exam` INT NULL DEFAULT 0,
  INDEX `fk_enrollments_courses1_idx` (`class_id` ASC) VISIBLE,
  CONSTRAINT `fk_enrollments_students`
    FOREIGN KEY (`student_id`)
    REFERENCES `software`.`students` (`student_id`)
    ON DELETE NO ACTION
    ON UPDATE CASCADE,
  CONSTRAINT `fk_enrollments_courses1`
    FOREIGN KEY (`class_id`)
    REFERENCES `software`.`courses` (`class_id`)
    ON DELETE CASCADE
    ON UPDATE NO ACTION)
ENGINE = InnoDB;
INSERT INTO enrollments VALUE (1,1,100,20,30);
INSERT INTO enrollments VALUE (1,3,50,default,30);
INSERT INTO enrollments VALUE (1,6,default,default,default);
 INSERT INTO enrollments VALUE (1,2,70,80,60);
INSERT INTO enrollments VALUE (2,1,90,70,85);
INSERT INTO enrollments VALUE (2,1,64,80,93);
INSERT INTO enrollments VALUE (3,1,100,default,default);
INSERT INTO enrollments VALUE (3,1,default,default,default);

SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
