|![Nihtiu Banner](/docs/images/Nihtiu_Banner.jpg)|
|--------:|
|*(air or wind in the extinct Chorotega language)*|

# Nihtiu Environment

## The situation

\#Covid19 is a disease caused by a \#coronavirus that appeared as an unexpected war, a situation that surprised everyone in late 2019. In a few months it has been able to decimate even the health systems of strong countries and is causing millions of sick people and thousands of deaths (with a really painful death).

At the time of this writing, we have to wait at least months (even around a year) to have a useful vaccine for the disease. Meanwhile, the only successful solution has been the so-called "social distancing", coupled with extreme measures of care and security when being in contact with others or leaving home in some type of forced quarantine at a country level. However, this is a very difficult situation to maintain that is destroying the world economy and will forever change the way our society works.

Key aspects of what needs to be done to resolve the problem lay around medical breathing technology which involves:

1. Patients, because in severe cases they need to be connected for weeks to special machines called "ventilators", which help them breathe. Many have died as there were not enough ventilators available when they reached that critical moment, and the hospital emergency rooms have not enough of them because in normal conditions is not necessary to use the resources purchasing so many expensive machines.  Also, there is a fierce battle in the open market for them and now the countries are forbidding to export any technology that could be used for Covid19 treatment, as it is needed locally everywhere. 
       
2. The economy, because when people are sick they cannot work and in order for healthy people to stay away from the disease, many have been confined far from their workplace. It is simply very dangerous to continue doing everything as usual and, with the lack of equipment in each country, the authorities chose to sacrifice the economy instead of the population.

There are also some features of the disease that have been discovered little by little, which paint a clearer picture of the situation:

* Some patients (the quantity is unknown right now because was not a priority to count them in the moment), have temporary or permanent damage in their lungs “after” being cataloged as cured.  There are cases where between 20 to 30% of their lung capacity have been lost1.
* The disease is very contagious2.
* Not only the ventilation devices are needed; in some countries, the quantity of doctors required to attend patients (and ultimately control the ventilators), is limited.  A reason for this to happen is that many of them are sick from the same disease they try to cure every day3, or simply they are exhaust or even near collapse because the overwhelming work needed to take care of the patients4.

This means considering a different type of breathing technology that is more comprehensive than currently available, where a single doctor has the possibility of offering treatment to more people and even, from a safer place than constantly visiting them. Furthermore, being a new and relatively unknown disease, every piece of information about how patients pass through the disease is important in helping others heal. It might even be necessary to collect detailed information from various countries in real time to understand what is happening with the disease and each type of treatment.
The Project

## Nihtiu

The project’s purpose is to describe distributed breathing technology for world-level war-like scenarios as the one the Covid-19 pandemic have defined.

As to create such type of technology is extremely demanding, following a standard working procedure would require many years of work that is not available at the moment.  For this reason, the project have been defined as a 100% open one using the flexible MIT licensing.

During the creation process, all reference documents, source code, blueprints, designs, pitfall descriptions, successful decisions, recommendations, suggestions, etc., will be published, for them to be useful as raw material for other projects where this information could be relevant.

Also, the idea is to use cheap and easy to find parts for each system component.  Instead of having only one medical-level ventilator, to be able to create several networked ones.  BUT with state of the art and carefully crafted definitions and industrial level quality code.

## The Environment

Taking all this into consideration, the Nihtiu Environment is defined:

![Nihtiu Environment](/docs/images/Nihtiu-Environment.png)

Here, there are ventilators, but they are networked and have centralized monitoring and control systems.  Also, there are portable breathing assistants, oriented to people with breathing problems but not critical enough to stay in the hospital.

And all them working as a whole, together with other medical equipment and data processing, to have a better understanding about what is really happening with the patient and the surrounding population.

The specific components are:

### Clinical Ventilators

These are the known ventilation devices that are being used in the fight with the Covid-19 disease.  The main difference is that these machines, although can work autonomously, can also be part of a critical network.  A good reference about what these system need to accomplish have been provided by the UK Department of Health & Social Care1.

In the case of the Nihtiu derived ventilators, they must be designed to work seamlessly in a Nihtiu environment.  Other ventilators could need a computing powered interface (relay machine) to be integrated as being Nihtiu ventilators.

### Portable Breathing Assistants

The PBA is a very small basic ventilation device that works connected to the wall electricity outlet and using batteries.  It is a Clinical Ventilator derived system having less mode operations and very simplified controls, designed for any non-technical and non-medical related person to work with.  But also, as the patient using it has reduced lung capacity, offers extra functionality, as a voice amplification or even a mobile talking complement.

The machine also have the capability to send telemetry data using cellular communication circuitry (phone derived), so even if it is being used outside the hospital, the doctors can continue monitoring what is happening with the patient while using the device.

The idea is to have a very cheap, light, reliable and small machine, and the basement to create this machine is the Nihtiu Clinical Ventilator.

### Data collector

The data collector is an information system that receives data from multiple sources and organize it according with the patient identity.

### Possible sources are:

* Clinical Ventilators
* Portable Breathing Assistants
* Data Processors
* Other medical systems, as the ones collect DICOM images connected through PACS servers.

It also provides enough logic for a doctor, nurse or medical technician to monitor certain quantity of patients (locally or remotely located).

### Data processor

This is a pure data processing device (Big Data, AI, etc.), that obtains data from the Data collector, analyze it and return new information to the information system in the Data collector to identify different types of situations are not obvious when only checking the direct telemetry data.

### Data visualization

The client-usable part of the environment.  This is a set of screens, voice controlled elements, etc., that permits to the medical staff to interact with the Nihtiu Environment.

Can be stationary stations, portable computing devices or even smartphones.

## The initial system

The initial work is to understand the problem and to define an initial ventilator system.

This system is a multi-computing device created with Arduinos and Single Board Computers, together with a set of sensors and actuators (motors, screens, sound devices, etc.).

As these are the basic elements, they are coded with enough care and clear enough terms for an information science professional to decode what is happening inside.  And the inner system behavior is like a transactional system instead of obscure and difficult to follow interleaved functionality.

## Related projects and references

[Botta: Specifications for a simple open source mechanical ventilator](https://docs.google.com/document/d/1FNPwrQjB1qW1330s5-S_-VB0vDHajMWKieJRjINCNeE/edit)

[Rapidly manufactured ventilator system specification](https://www.gov.uk/government/publications/coronavirus-covid-19-ventilator-supply-specification/rapidly-manufactured-ventilator-system-specification)

[Coronavirus: some recovered patients may have reduced lung function and are left gasping for air while walking briskly, Hong Kong doctors find](https://www.scmp.com/news/hong-kong/health-environment/article/3074988/coronavirus-some-recovered-patients-may-have)

[How The Novel Coronavirus And The Flu Are Alike ... And Different](https://www.npr.org/sections/goatsandsoda/2020/03/20/815408287/how-the-novel-coronavirus-and-the-flu-are-alike-and-differen)

[Coronavirus: One in four NHS doctors 'sick or in isolation'](https://news.sky.com/story/coronavirus-one-in-four-nhs-doctors-sick-or-in-isolation-11965886)

[Doctors: COVID-19 pushing Italian ICUs toward collapse](https://www.cidrap.umn.edu/news-perspective/2020/03/doctors-covid-19-pushing-italian-icus-toward-collapse)

[Code Live Ventilator Challenge](https://www.agorize.com/en/challenges/code-life-challenge)

[7 open hardware projects working to solve COVID-19](https://opensource.com/article/20/3/open-hardware-covid19)

[IFIXIT: Help us crowdsource repair information for medical equipment](https://www.ifixit.com/News/36354/help-us-crowdsource-repair-information-for-Hospital-Equipment)

[OXYGEN](https://www.oxygen.protofy.xyz/)

[UCR:Respiradores de emergencia para pacientes de Covid 19 podrían ser de fácil construcción](https://www.ucr.ac.cr/noticias/2020/03/25/respiradores-de-emergencia-para-pacientes-de-covid-19-podrian-ser-de-facil-construccion.html)

[TEC trabaja en la creación de respiradores artificiales](https://delfino.cr/2020/03/tec-trabaja-en-la-creacion-de-respiradores-artificiales)

[How innovation is helping ease a dangerous ventilator shortage](https://www.weforum.org/agenda/2020/03/coronavirus-ventilators-covid19-healthcare/)
