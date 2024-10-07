# Neuronales Netzwerk von Grund auf in C++

[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/HasiKe/NeuralNetwork/blob/main/README.md)
[![de](https://img.shields.io/badge/lang-de-red.svg)](https://github.com/HasiKe/NeuralNetwork/blob/main/docs/de/README.md)


<p>Dieses Projekt implementiert ein einfaches neuronales Netzwerk in C++ ohne Verwendung externer Machine-Learning-Bibliotheken. Es bietet Funktionen zum Trainieren, Speichern und Laden des Netzwerks sowie zur Bewertung seiner Leistung auf einem gegebenen Datensatz.</p>


## Über das Projekt
<p>Das Ziel dieses Projekts ist es, die Grundlagen neuronaler Netzwerke zu verstehen, indem ein Netzwerk von Grund auf in C++ implementiert wird. Es dient als Lernressource und bietet Einblicke in die Implementierung von Forward- und Backpropagation, Gewichtsanpassungen sowie in das Speichern und Laden von Modellen.</p>

## Funktionen
* Eigenständiges neuronales Netzwerk: Keine externen Bibliotheken erforderlich.
+ Speicher- und Ladefunktionen: Speichern Sie trainierte Modelle und laden Sie sie für zukünftige Vorhersagen.
+ Leistungsbewertung: Vergleichen Sie die Genauigkeit des Netzwerks vor und nach dem Training.
+ Benutzerinteraktion: Das Programm informiert den Benutzer über Leistungsänderungen und fragt, ob das Modell gespeichert werden soll.

<!-- GETTING STARTED -->
## Getting Started

## Voraussetzungen
<p> C++ Compiler: Unterstützt mindestens C++11.<br>
CMake: Zum Bauen des Projekts.<br>
Standardbibliotheken: Keine zusätzlichen Bibliotheken erforderlich.<p>

## Installation
Repository klonen

```bash
git clone https://github.com/IhrBenutzername/NeuralNetwork.git
cd NeuralNetwork
```
Build-Verzeichnis erstellen und zum Verzeichnis navigieren

```bash
mkdir build
cd build
```
Projekt mit CMake konfigurieren

```bash
cmake ..
```
Projekt bauen

```bash
make
```

<!-- Usage -->
## Verwendung
Nach erfolgreichem Build können Sie das Programm ausführen:

```bash
./NN
```
Das Programm führt folgende Schritte aus:

<p> 1. Datensatz laden: Der Seeds-Datensatz wird aus dem Verzeichnis data/ geladen und normalisiert.
2.Netzwerkinitialisierung oder -laden: Überprüft, ob ein gespeichertes Netzwerk vorhanden ist. Falls ja, wird es geladen; andernfalls wird ein neues Netzwerk initialisiert.<br>
3. Leistungsbewertung vor dem Training: Die Genauigkeit des Netzwerks wird auf dem Datensatz gemessen.<br>
4. Training des Netzwerks: Das Netzwerk wird mit den angegebenen Hyperparametern trainiert.<br>
5. Leistungsbewertung nach dem Training: Die Genauigkeit wird erneut gemessen und mit der vorherigen verglichen.<br>
6. Speicheroption: Der Benutzer wird gefragt, ob das trainierte Netzwerk gespeichert werden soll.</p>


## Projektstruktur
- src/: 
    - Source code of the project.
- include/:
    - Header files for the project.
- data/:
    - Dataset files (e.g., seeds_dataset.csv).
- build/:
    - Build directory (after creation).

## Anpassung der Hyperparameter
Sie können die Hyperparameter des Netzwerks direkt in der main.cpp anpassen:

- n_hidden: Anzahl der Neuronen in der versteckten Schicht.
- l_rate: Lernrate für die Gewichtsanpassung.
- n_epoch: Anzahl der Epochen für das Training.
```c++
int n_hidden = 5;     // Anzahl der Neuronen in der versteckten Schicht
float l_rate = 0.2f;  // Lernrate
int n_epoch = 500;    // Anzahl der Trainingsdurchläufe
```

## Daten vorbereiten
Stellen Sie sicher, dass der Seeds-Datensatz im Verzeichnis data/ vorhanden ist und den Namen seeds_dataset.csv trägt. Der Pfad zum Datensatz wird in der main.cpp festgelegt:

```c++
csv_data = load_csv_data("data/seeds_dataset.csv");
```
Falls der Datensatz an einem anderen Ort liegt, passen Sie den Pfad entsprechend an.

<!-- TODO -->
# TODO
- [ ] setzte die learn rate automatisch
- [ ] Hinzufügen von verschiedenen Neuronen Typen