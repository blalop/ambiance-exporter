EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ESP8266:NodeMCU1.0(ESP-12E) U?
U 1 1 612B755A
P 3750 3700
F 0 "U?" H 3750 4787 60  0000 C CNN
F 1 "NodeMCU1.0(ESP-12E)" H 3750 4681 60  0000 C CNN
F 2 "" H 3150 2850 60  0000 C CNN
F 3 "" H 3150 2850 60  0000 C CNN
	1    3750 3700
	1    0    0    -1  
$EndComp
$Comp
L Sensor:DHT11 U?
U 1 1 612B876E
P 5700 3950
F 0 "U?" H 5456 3996 50  0000 R CNN
F 1 "DHT22" H 5456 3905 50  0000 R CNN
F 2 "Sensor:Aosong_DHT11_5.5x12.0_P2.54mm" H 5700 3550 50  0001 C CNN
F 3 "http://akizukidenshi.com/download/ds/aosong/DHT11.pdf" H 5850 4200 50  0001 C CNN
	1    5700 3950
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 612B8FAD
P 6300 3050
F 0 "R?" H 6370 3096 50  0000 L CNN
F 1 "10k" H 6370 3005 50  0000 L CNN
F 2 "" V 6230 3050 50  0001 C CNN
F 3 "~" H 6300 3050 50  0001 C CNN
	1    6300 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4550 4300 5700 4300
Wire Wire Line
	5700 4300 5700 4250
Wire Wire Line
	4550 4400 6650 4400
Wire Wire Line
	6650 4400 6650 2900
Wire Wire Line
	5700 2900 5700 3650
Wire Wire Line
	5700 2900 6300 2900
Connection ~ 6300 2900
Wire Wire Line
	6300 2900 6650 2900
Wire Wire Line
	4550 3200 6300 3200
Wire Wire Line
	6000 3950 6300 3950
Wire Wire Line
	6300 3950 6300 3200
Connection ~ 6300 3200
$EndSCHEMATC
