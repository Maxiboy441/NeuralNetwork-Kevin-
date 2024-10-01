# Neuronales Netzwerk von Grund auf in C++
Dieses Projekt implementiert ein einfaches neuronales Netzwerk in C++ ohne Verwendung externer Machine-Learning-Bibliotheken. Es bietet Funktionen zum Trainieren, Speichern und Laden des Netzwerks sowie zur Bewertung seiner Leistung auf einem gegebenen Datensatz.

## Inhaltsverzeichnis
Über das Projekt
Funktionen
Voraussetzungen
Installation
Verwendung
Beispielausgabe
Projektstruktur
Mitwirkende
Lizenz

## Über das Projekt
Das Ziel dieses Projekts ist es, die Grundlagen neuronaler Netzwerke zu verstehen, indem ein Netzwerk von Grund auf in C++ implementiert wird. Es dient als Lernressource und bietet Einblicke in die Implementierung von Forward- und Backpropagation, Gewichtsanpassungen sowie in das Speichern und Laden von Modellen.

## Funktionen
Eigenständiges neuronales Netzwerk: Keine externen Bibliotheken erforderlich.
Speicher- und Ladefunktionen: Speichern Sie trainierte Modelle und laden Sie sie für zukünftige Vorhersagen.
Leistungsbewertung: Vergleichen Sie die Genauigkeit des Netzwerks vor und nach dem Training.
Benutzerinteraktion: Das Programm informiert den Benutzer über Leistungsänderungen und fragt, ob das Modell gespeichert werden soll.

## Voraussetzungen
C++ Compiler: Unterstützt mindestens C++11.
CMake: Zum Bauen des Projekts.
Standardbibliotheken: Keine zusätzlichen Bibliotheken erforderlich.

## Installation
Repository klonen

```
git clone https://github.com/IhrBenutzername/NeuralNetwork.git
cd NeuralNetwork
```
Build-Verzeichnis erstellen und zum Verzeichnis navigieren

```
mkdir build
cd build
```
Projekt mit CMake konfigurieren

```
cmake ..
```
Projekt bauen

```
make
```

## Verwendung
Nach erfolgreichem Build können Sie das Programm ausführen:

```
./NN
```
Das Programm führt folgende Schritte aus:

Datensatz laden: Der Seeds-Datensatz wird aus dem Verzeichnis data/ geladen und normalisiert.

Netzwerkinitialisierung oder -laden: Überprüft, ob ein gespeichertes Netzwerk vorhanden ist. Falls ja, wird es geladen; andernfalls wird ein neues Netzwerk initialisiert.

Leistungsbewertung vor dem Training: Die Genauigkeit des Netzwerks wird auf dem Datensatz gemessen.

Training des Netzwerks: Das Netzwerk wird mit den angegebenen Hyperparametern trainiert.

Leistungsbewertung nach dem Training: Die Genauigkeit wird erneut gemessen und mit der vorherigen verglichen.

Speicheroption: Der Benutzer wird gefragt, ob das trainierte Netzwerk gespeichert werden soll.


## Projektstruktur
src/: Quellcode des Projekts.
main.cpp: Hauptprogramm mit dem Ablauf des Netzwerks.
NeuralNetwork.cpp/h: Implementierung des Netzwerks mit Speicher- und Ladefunktionen.
Layer.cpp/h: Implementierung der Schichten des Netzwerks.
Neuron.cpp/h: Implementierung der Neuronen.
include/: Header-Dateien für das Projekt.
data/: Datensatzdateien (z. B. seeds_dataset.csv).
build/: Build-Verzeichnis (nach Erstellung).
CMakeLists.txt: CMake-Build-Konfigurationsdatei.

## Anpassung der Hyperparameter
Sie können die Hyperparameter des Netzwerks direkt in der main.cpp anpassen:

n_hidden: Anzahl der Neuronen in der versteckten Schicht.
l_rate: Lernrate für die Gewichtsanpassung.
n_epoch: Anzahl der Epochen für das Training.
```
int n_hidden = 5;     // Anzahl der Neuronen in der versteckten Schicht
float l_rate = 0.2f;  // Lernrate
int n_epoch = 500;    // Anzahl der Trainingsdurchläufe
```
## Daten vorbereiten
Stellen Sie sicher, dass der Seeds-Datensatz im Verzeichnis data/ vorhanden ist und den Namen seeds_dataset.csv trägt. Der Pfad zum Datensatz wird in der main.cpp festgelegt:

```
csv_data = load_csv_data("data/seeds_dataset.csv");
```
Falls der Datensatz an einem anderen Ort liegt, passen Sie den Pfad entsprechend an.

## Mitwirkende
Ihr Name - Initiale Arbeit - IhrGitHubBenutzername
Lizenz
Dieses Projekt ist unter der MIT-Lizenz lizenziert – Details finden Sie in der LICENSE-Datei.

## Danksagung
Inspiriert von Lernressourcen über neuronale Netzwerke und maschinelles Lernen.
Besonderer Dank an alle Open-Source-Beiträge und Community-Mitglieder.

## Kontakt
Falls Sie Fragen haben oder einen Beitrag leisten möchten, können Sie mich gerne kontaktieren:

E-Mail: kevin@hasike.de
GitHub: @HasiKe