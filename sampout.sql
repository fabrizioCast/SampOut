-- phpMyAdmin SQL Dump
-- version 5.0.2
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 06-03-2021 a las 17:51:16
-- Versión del servidor: 10.4.14-MariaDB
-- Versión de PHP: 7.2.33

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `sampout`
--

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `grupos`
--

CREATE TABLE `grupos` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(20) NOT NULL,
  `Color` int(30) NOT NULL,
  `Owner` varchar(26) NOT NULL,
  `Miembros` int(11) NOT NULL,
  `Territorio` int(11) NOT NULL,
  `GangZone` int(11) NOT NULL,
  `AreaID` int(11) NOT NULL,
  `minX` float NOT NULL,
  `minY` float NOT NULL,
  `maxX` float NOT NULL,
  `maxY` float NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `grupos`
--

INSERT INTO `grupos` (`ID`, `Nombre`, `Color`, `Owner`, `Miembros`, `Territorio`, `GangZone`, `AreaID`, `minX`, `minY`, `maxX`, `maxY`) VALUES
(1, 'Pijudos', -1125763585, 'Sleek', 1, 1, 0, 1, 2251.21, -786.925, 2451.21, -586.925),
(2, 'Sin Nombre', -1704361729, 'Sleek_Wayne', 1, 0, 0, 2, 0, 0, 0, 0),
(5, 'Nada jeje', -658021633, 'Sleek_Si', 1, 0, 0, 3, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `hierro`
--

CREATE TABLE `hierro` (
  `ID` int(11) NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `ModelID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `hierro`
--

INSERT INTO `hierro` (`ID`, `PosX`, `PosY`, `PosZ`, `ModelID`) VALUES
(1, 2389.48, -682.269, 125.923, 1304),
(2, 2387.29, -682.489, 125.956, 1304),
(3, 2406.07, -1038.99, 50.3203, 1304);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inventario`
--

CREATE TABLE `inventario` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(26) NOT NULL,
  `Slot1` int(11) NOT NULL,
  `Slot2` int(11) NOT NULL,
  `Slot3` int(11) NOT NULL,
  `Slot4` int(11) NOT NULL,
  `Slot5` int(11) NOT NULL,
  `Slot6` int(11) NOT NULL,
  `Slot7` int(11) NOT NULL,
  `Slot8` int(11) NOT NULL,
  `Slot9` int(11) NOT NULL,
  `Slot10` int(11) NOT NULL,
  `Slot11` int(11) NOT NULL,
  `Slot12` int(11) NOT NULL,
  `Slot13` int(11) NOT NULL,
  `Slot14` int(11) NOT NULL,
  `Slot15` int(11) NOT NULL,
  `Usos1` int(11) NOT NULL,
  `Usos2` int(11) NOT NULL,
  `Usos3` int(11) NOT NULL,
  `Usos4` int(11) NOT NULL,
  `Usos5` int(11) NOT NULL,
  `Usos6` int(11) NOT NULL,
  `Usos7` int(11) NOT NULL,
  `Usos8` int(11) NOT NULL,
  `Usos9` int(11) NOT NULL,
  `Usos10` int(11) NOT NULL,
  `Usos11` int(11) NOT NULL,
  `Usos12` int(11) NOT NULL,
  `Usos13` int(11) NOT NULL,
  `Usos14` int(11) NOT NULL,
  `Usos15` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `inventario`
--

INSERT INTO `inventario` (`ID`, `Nombre`, `Slot1`, `Slot2`, `Slot3`, `Slot4`, `Slot5`, `Slot6`, `Slot7`, `Slot8`, `Slot9`, `Slot10`, `Slot11`, `Slot12`, `Slot13`, `Slot14`, `Slot15`, `Usos1`, `Usos2`, `Usos3`, `Usos4`, `Usos5`, `Usos6`, `Usos7`, `Usos8`, `Usos9`, `Usos10`, `Usos11`, `Usos12`, `Usos13`, `Usos14`, `Usos15`) VALUES
(15, 'Sleek_Wayne', 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(16, 'Sleek', 13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `madera`
--

CREATE TABLE `madera` (
  `ID` int(10) NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `ModelID` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `madera`
--

INSERT INTO `madera` (`ID`, `PosX`, `PosY`, `PosZ`, `ModelID`) VALUES
(1, 2383.97, -645.181, 126.359, 671),
(2, 2390.71, -659.443, 126.885, 671),
(3, 2389.76, -672.181, 126.192, 664),
(4, 2398.95, -674.703, 125.921, 671),
(5, 2396.84, -684.267, 125.142, 664),
(6, 2398.79, -663.677, 126.979, 671);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `objetos`
--

CREATE TABLE `objetos` (
  `ID` int(15) NOT NULL,
  `ModelID` int(15) NOT NULL,
  `Owner` varchar(26) NOT NULL,
  `Vida` float NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `RotX` float NOT NULL,
  `RotY` float NOT NULL,
  `RotZ` float NOT NULL,
  `Password` varchar(5) NOT NULL,
  `gPassword` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `objetos`
--

INSERT INTO `objetos` (`ID`, `ModelID`, `Owner`, `Vida`, `PosX`, `PosY`, `PosZ`, `RotX`, `RotY`, `RotZ`, `Password`, `gPassword`) VALUES
(1, 1498, 'Sleek', 1000, 2415.53, -1042.92, 50.2147, 0, 0, 0, '1236', 1),
(3, 980, 'Sleek', 1000, 2398.58, -1050.2, 53.4602, 0, 0, 38.3, '1234', 1),
(2, 1497, 'Sleek', 1000, 2407.9, -1047.49, 51.3683, 0, 0, 0, '1235', 1),
(4, 3749, 'Sleek', 1000, 2370.23, -650.065, 129.932, 0, 0, 0, '0000', 0),
(5, 987, 'Sleek', 1000, 2388.22, -632.761, 124.86, 0, 0, 0, '0000', 0),
(6, 987, 'Sleek', 1000, 2400.2, -632.888, 124.719, 0, 0, 0, '0000', 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `objetosplayer`
--

CREATE TABLE `objetosplayer` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(26) NOT NULL,
  `GetRadio` int(11) NOT NULL,
  `BateriasRadio` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `objetosplayer`
--

INSERT INTO `objetosplayer` (`ID`, `Nombre`, `GetRadio`, `BateriasRadio`) VALUES
(13, 'Sleek', 0, 0),
(14, 'Sleek_Wayne', 0, 0),
(15, 'Sleek_Wayne', 0, 0),
(16, 'Sleek', 0, 0);

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `usuarios`
--

CREATE TABLE `usuarios` (
  `ID` int(11) NOT NULL,
  `Nombre` varchar(26) NOT NULL,
  `Password` varchar(65) NOT NULL,
  `Email` varchar(128) NOT NULL,
  `Edad` int(11) NOT NULL,
  `EdadPJ` int(11) NOT NULL,
  `PosX` float NOT NULL,
  `PosY` float NOT NULL,
  `PosZ` float NOT NULL,
  `Skin` int(3) NOT NULL,
  `Hambre` float NOT NULL,
  `Sed` float NOT NULL,
  `Vida` float NOT NULL,
  `Coin` int(11) NOT NULL,
  `GrupoID` int(11) NOT NULL,
  `Grupo` int(11) NOT NULL,
  `GrupoLider` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Volcado de datos para la tabla `usuarios`
--

INSERT INTO `usuarios` (`ID`, `Nombre`, `Password`, `Email`, `Edad`, `EdadPJ`, `PosX`, `PosY`, `PosZ`, `Skin`, `Hambre`, `Sed`, `Vida`, `Coin`, `GrupoID`, `Grupo`, `GrupoLider`) VALUES
(15, 'Sleek_Wayne', 'rihana91', '22@gmmail.com', 22, 25, 2351.99, -686.991, 117.304, 13, 50, 50, 100, 0, 0, 0, 0),
(16, 'Sleek', 'rihana91', 'alskas@gmail.com', 22, 26, 2351.1, -688.13, 117.304, 13, 50, 50, 100, 0, 0, 0, 0);

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `grupos`
--
ALTER TABLE `grupos`
  ADD PRIMARY KEY (`ID`);

--
-- Indices de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `grupos`
--
ALTER TABLE `grupos`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=6;

--
-- AUTO_INCREMENT de la tabla `usuarios`
--
ALTER TABLE `usuarios`
  MODIFY `ID` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=17;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
