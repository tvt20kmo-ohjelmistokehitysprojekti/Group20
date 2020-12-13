-- MySQL Script generated by MySQL Workbench
-- Sun Dec 13 03:40:10 2020
-- Model: New Model    Version: 1.0
-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema opisk_t9ylan01
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema opisk_t9ylan01
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `opisk_t9ylan01` ;
USE `opisk_t9ylan01` ;

-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`account`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`account` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `balance` INT NOT NULL,
  `minimum` INT NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`owner`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`owner` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `name` VARCHAR(64) NOT NULL,
  `ss_number` VARCHAR(45) NULL DEFAULT NULL COMMENT 'possible values:\\n\\nperson\\ncompany\\nmachine',
  `is_machine` TINYINT NULL DEFAULT NULL,
  `is_company` TINYINT NULL DEFAULT NULL,
  `is_human` TINYINT NULL DEFAULT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) ,
  UNIQUE INDEX `ss_number_UNIQUE` (`ss_number` ASC) )
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`card`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`card` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `owner_ID` INT NOT NULL,
  `card_number` VARCHAR(45) NOT NULL COMMENT 'Not number, varchar\n',
  `salt_and_hash` VARCHAR(300) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) ,
  UNIQUE INDEX `cardNumber_UNIQUE` (`card_number` ASC) ,
  INDEX `fk_card_person1_idx` (`owner_ID` ASC) ,
  UNIQUE INDEX `person_ID_UNIQUE` (`owner_ID` ASC) ,
  CONSTRAINT `fk_card_person1`
    FOREIGN KEY (`owner_ID`)
    REFERENCES `opisk_t9ylan01`.`owner` (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`account-card`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`account-card` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `account_ID` INT NOT NULL,
  `card_ID` INT NOT NULL,
  INDEX `fk_account-card_account1_idx` (`account_ID` ASC) ,
  INDEX `fk_account-card_card1_idx` (`card_ID` ASC) ,
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) ,
  PRIMARY KEY (`ID`),
  CONSTRAINT `fk_account-card_account1`
    FOREIGN KEY (`account_ID`)
    REFERENCES `opisk_t9ylan01`.`account` (`ID`),
  CONSTRAINT `fk_account-card_card1`
    FOREIGN KEY (`card_ID`)
    REFERENCES `opisk_t9ylan01`.`card` (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`machine`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`machine` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `owner_ID` INT NOT NULL,
  `salt_and_hash` VARCHAR(300) NOT NULL,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) ,
  INDEX `fk_machine_owner1_idx` (`owner_ID` ASC) ,
  CONSTRAINT `fk_machine_owner1`
    FOREIGN KEY (`owner_ID`)
    REFERENCES `opisk_t9ylan01`.`owner` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`owner-account`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`owner-account` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `owner_ID` INT NOT NULL,
  `account_ID` INT NOT NULL,
  INDEX `fk_person-account_person_idx` (`owner_ID` ASC) ,
  INDEX `fk_person-account_account1_idx` (`account_ID` ASC) ,
  PRIMARY KEY (`ID`),
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) ,
  CONSTRAINT `fk_person-account_account1`
    FOREIGN KEY (`account_ID`)
    REFERENCES `opisk_t9ylan01`.`account` (`ID`),
  CONSTRAINT `fk_person-account_person`
    FOREIGN KEY (`owner_ID`)
    REFERENCES `opisk_t9ylan01`.`owner` (`ID`))
ENGINE = InnoDB
DEFAULT CHARACTER SET = utf8mb4
COLLATE = utf8mb4_unicode_ci;


-- -----------------------------------------------------
-- Table `opisk_t9ylan01`.`transaction`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `opisk_t9ylan01`.`transaction` (
  `ID` INT NOT NULL AUTO_INCREMENT,
  `account_ID` INT NOT NULL,
  `other_account_ID` INT NULL DEFAULT NULL,
  `other_transaction_ID` INT NULL DEFAULT NULL,
  `time` DATETIME NOT NULL,
  `type` VARCHAR(45) NULL COMMENT 'withdrawal/transfer',
  `balance_before` INT NULL DEFAULT NULL,
  `balance_change` INT NOT NULL,
  `balance_after` INT NULL DEFAULT NULL,
  UNIQUE INDEX `ID_UNIQUE` (`ID` ASC) ,
  INDEX `fk_transaction_account1_idx` (`account_ID` ASC) ,
  INDEX `fk_transaction_account2_idx` (`other_account_ID` ASC) ,
  INDEX `fk_transaction_transaction1_idx` (`other_transaction_ID` ASC) ,
  PRIMARY KEY (`ID`),
  CONSTRAINT `fk_transaction_account1`
    FOREIGN KEY (`account_ID`)
    REFERENCES `opisk_t9ylan01`.`account` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_transaction_account2`
    FOREIGN KEY (`other_account_ID`)
    REFERENCES `opisk_t9ylan01`.`account` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION,
  CONSTRAINT `fk_transaction_transaction1`
    FOREIGN KEY (`other_transaction_ID`)
    REFERENCES `opisk_t9ylan01`.`transaction` (`ID`)
    ON DELETE NO ACTION
    ON UPDATE NO ACTION)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;
