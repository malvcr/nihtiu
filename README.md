![Nihtiu Banner](https://github.com/malvcr/nihtiu/blob/master/docs/images/Nihtiu_Banner.jpg)
<div style="text-align: right"><i>(air or wind on the Chorotega extinct language)</i></div>


The purpose of this project is to discuss and to provide/invent solutions to deal with the lack of equipment to work with the #Covid-19 #coronavirus.

The idea has been taken from Johns Hopkins Emergency Medicine Resident Julian Botta (Twitter: @julianbotta) published document ["Specifications for simple open source mechanical ventilator"](https://docs.google.com/document/d/1FNPwrQjB1qW1330s5-S_-VB0vDHajMWKieJRjINCNeE/preview?fbclid=IwAR3ugu1SGMsacwKi6ycAKJFOMduInSO4WVM8rgmC4CgMJY6cKaGBNR14mpM), together with other technical and theoretical sources and some spice from the project creator.

There are several alternatives to work the problems:

* To design and to create new systems
* To retrofit obsolete or damaged existing machines
* To addapt existing equipment and/or parts to be used in the needed context

# A Botta System

## General description

Botta describes a system whose control could be performed by Arduino or Raspberry Pi machines.

There is the main issue the machine must accomplish, although there seem to be more related problems.

* The lack of other medical material
* Many patients and small quantity of exhausted medical staff
* Physical space for patient accomodation
* A very dangerous contagious environment

As the machines must be carefully tuned for each case, an knowledable person must check what is happening to re-tune the machine.  If the machine is an independent device, that must be done being there with the person.

So, it seems more appropriate to network the machines and to have an isolated remote control center that could monitor what is happening with each machine and that can deliver the required commands to each one.

Oh the other side, it is easier to create hardware and sensor control logic using Arduino level machines that Single Board Computers.  But Arduino logic for a networked environment could be very difficult to obtain.  

A possible solution is to use both, an Arduino and a Raspberry Pi or similar machine connected through a USB cable.

* The Arduino, ESP32 or similar device is the real heart of the system.  It has the machine logic, parameters, profiles, receives data from the sensors and manages the moving parts.
* The SBC is the "Access Server", providing user interfacing, alarms and local telemetry data storage.
* An analysis and backup system "could" (optionally) connect with the SBC to collect the working information to perform several types of analysis on the systems.  That connection could be performed wired or wirelessly as it is not critical fot the machine behaviour.

All the data visualization could be done with HTTP5 logic.  A first version can be done with PHP or similar type of language, while the Arduino logic be encoded with carefully written C++ code (medical level quality).

This setup advantage is that the complexity can be limited to the particular scenario and that, in the case the networed environment fails, the Arduino machine can continue working as such embedded systems can work in isolation from the other computing elements.  This, together with some "emergency" setup for immediate usage.

## Transactional based

Although there are and will be attempts to create these systems as pure embedded ones, it seems better to work them as transactional based machines.

These, together with a standardized basic protocol could permit to "match" different independent attempts.  Some could work a better ventilator or similar, but other a better control system.  Some place could work with a Raspberry Pi but another one maybe have some spare old PCs that could be useful for that purpose.

Even a equipment company could work the "difficult to make" parts but in quantity, letting the control area to other company or individuals.

All them sending transactions through network to the particular machines.  A control system could work with one ventilator while another could manage one thousand.

*Note: WIFI was initially considered for the control network; however, concerns about wireless technology reliability is making this a secondary control channel, letting the main one as a pure wire connected one.  Anyway, always will be possible to link a SBC with an Ethernet port AND a WIFI link.  This is the main reason to have a mixed environment (Arduino+SBC), as the SBC can provide extra flexibility methods lething to the Arduino the precise hard work to keep the patient alive.*

# Why retrofiting equipment?

This is important when some element in the setup is not easy to create.

Existing machines that are no longer into production could be reassembled and, with some modifications, could provide the basic functions.

Also, they have "complex" parts that can be used to create a Botta System.

# Part adaptation

In this case, the system could use some already created parts, even replacement parts created to specific medical equipment.

In all these cases the challenge is how to obtain a minimum usable working machine, not a full fleated deluxe system (this is a WAR ZONE where many characteristics must be avoided).

# DIY sense

This type of systems can't be designed for complex built scenarios as, in many cases, the sophisticated infrastructure doesn't exist.

This is why an Arduino or a Raspberry Pi are being discussed and not more complex control machines.  However, the software by itself could be complex, just that the software setup must be extremely easy to accomplish, as the people involved with the immediate patient treatment need the machines working quickly and have no time to read manuals.

# Related projects

[Code Live Ventilator Challenge](https://www.agorize.com/en/challenges/code-life-challenge)

[7 open hardware projects working to solve COVID-19](https://opensource.com/article/20/3/open-hardware-covid19)

[IFIXIT: Help us crowdsource repair information for medical equipment](https://www.ifixit.com/News/36354/help-us-crowdsource-repair-information-for-Hospital-Equipment)

[OXYGEN](https://www.oxygen.protofy.xyz/)

[UCR:Respiradores de emergencia para pacientes de Covid 19 podrían ser de fácil construcción](https://www.ucr.ac.cr/noticias/2020/03/25/respiradores-de-emergencia-para-pacientes-de-covid-19-podrian-ser-de-facil-construccion.html)

[TEC trabaja en la creación de respiradores artificiales](https://delfino.cr/2020/03/tec-trabaja-en-la-creacion-de-respiradores-artificiales)
