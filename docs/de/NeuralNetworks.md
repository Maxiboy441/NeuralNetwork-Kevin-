# Übersicht über verschiedene Arten von neuronalen Netzen und ihre Stärken und Schwächen
<a id="top"></a>

[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/HasiKe/NeuralNetwork/docs/en/NeuralNetworks.md)
[![de](https://img.shields.io/badge/lang-de-red.svg)](https://github.com/HasiKe/NeuralNetwork/dosc/de/NeuralNetworks.md)
<br>

---
<a href="#Type-1">1. Feedforward-Neuronale Netze (FNN) / Mehrschichtige Perzeptrons (MLP)</a><br>
<a href="#Type-2">2. Konvolutionale Neuronale Netze (CNN)</a><br>
<a href="#Type-3">3. Rekurrente Neuronale Netze (RNN)</a><br>
<a href="#Type-4">4. Long Short-Term Memory (LSTM)</a><br>
<a href="#Type-5">5. Gated Recurrent Units (GRU)</a><br>
<a href="#Type-6">6. Autoencoder</a><br>
<a href="#Type-7">7. Generative Adversarial Networks (GANs)</a><br>
<a href="#Type-8">8. Transformer</a><br>
<a href="#Type-9">9. Graph Neuronale Netze (GNN)</a><br>
<a href="#Type-10">10. Selbstorganisierende Karten (SOMs)</a><br>
<a href="#Type-11">11. Boltzmann-Maschinen</a><br>
<a href="#Type-12">12. Hopfield-Netze</a><br>
<a href="#Type-13">13. Capsule Networks</a>

---

<!-- FNN / MLP -->
## <h id="Type-1"> 1. Feedforward-Neuronale Netze (FNN) / Mehrschichtige Perzeptrons (MLP) </h>

 Feedforward-Netze sind die einfachste Form neuronaler Netze, bei denen die Informationen nur in eine Richtung von den Eingabeschichten über die verborgenen Schichten zu den Ausgabeschichten fließen.

#### Stärken:

+ Einfachheit: Leicht zu verstehen und zu implementieren.<br>
+ Vielseitigkeit: Geeignet für eine Vielzahl von Aufgaben wie Klassifikation und Regression.<br>
+ Effizienz: Relativ geringer Rechenaufwand im Vergleich zu komplexeren Modellen.<br>

#### Schwächen:

+ Keine Speicherfähigkeit: Unfähig, zeitliche oder sequentielle Abhängigkeiten zu modellieren.<br>
+ Überanpassung: Neigung zu Overfitting, insbesondere bei kleinen Datensätzen.<br>
+ Datenbedarf: Kann große Mengen an Trainingsdaten erfordern, um gut zu generalisieren.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- CNN -->
## <h id="Type-2"> 2. Konvolutionale Neuronale Netze (CNN) <h>

CNNs sind speziell für die Verarbeitung von Daten mit gridartigen Topologien konzipiert, wie z. B. Bilder. Sie nutzen Faltungsschichten, um lokale Muster zu erkennen.

#### Stärken:

+ Lokale Konnektivität: Effektiv bei der Erkennung von lokalen Merkmalen in Daten.<br>
+ Gewichtsfreigabe: Reduziert die Anzahl der zu lernenden Parameter.<br>
+ Leistungsfähigkeit: Hervorragende Ergebnisse in Bereichen wie Bild- und Spracherkennung.<br>

#### Schwächen:

+ Datenintensiv: Benötigen große Mengen an gelabelten Daten.<br>
+ Rechenaufwand: Hoher Bedarf an Speicher und Verarbeitungskraft, insbesondere bei großen Modellen.<br>
+ Eingabebeschränkung: Weniger effektiv für nicht-bildliche oder unstrukturierte Daten.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- RNN -->
## <h id="Type-3"> 3. Rekurrente Neuronale Netze (RNN) <h>

RNNs sind darauf ausgelegt, sequentielle Daten zu verarbeiten, indem sie vorherige Informationen durch Schleifen im Netzwerk speichern.

#### Stärken:

+ Sequenzmodellierung: Ideal für Zeitreihen, Text und andere sequentielle Daten.<br>
+ Gedächtnisfähigkeit: Können Informationen aus früheren Eingaben berücksichtigen.<br>
+ Flexibilität: Anwendbar auf variable Eingabelängen.<br>

#### Schwächen:

+ Vanishing Gradient Problem: Schwierigkeiten beim Lernen von Langzeitabhängigkeiten.<br>
+ Training: Kann langsam und komplex sein.<br>
+ Instabilität: Anfällig für explodierende Gradienten.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LSTM -->
## <h id="Type-4"> 4. Long Short-Term Memory (LSTM) <h>

Eine Erweiterung von RNNs, die spezielle Einheiten enthält, um das Vanishing Gradient Problem zu überwinden.

#### Stärken:

+ Langzeitabhängigkeiten: Effektiv beim Lernen von Beziehungen über längere Sequenzen.<br>
+ Robustheit: Besseres Handling von Rauschen und Variabilität in Daten.<br>
+ Weit verbreitet: Standard in vielen Anwendungen der Sprach- und Zeitreihenverarbeitung.<br>

#### Schwächen:

+ Komplexität: Mehr Parameter führen zu längeren Trainingszeiten.<br>
+ Rechenintensiv: Erhöhte Anforderungen an Speicher und Verarbeitung.<br>
+ Überanpassung: Risiko bei kleinen Datensätzen ohne geeignete Regularisierung.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GRU -->
## <h id="Type-5"> 5. Gated Recurrent Units (GRU) <h>

Eine vereinfachte Version von LSTM mit weniger Parametern.

#### Stärken:

+ Effizienz: Schneller zu trainieren als LSTM.<br>
+ Performance: Vergleichbare Ergebnisse bei vielen Aufgaben.<br>
+ Einfachheit: Weniger komplexe Architektur.<br>

#### Schwächen:

+ Flexibilität: Weniger Anpassungsmöglichkeiten als LSTM.<br>
+ Leistungsgrenze: Möglicherweise nicht so effektiv bei sehr langen Sequenzen.<br>
+ Anwendungsspezifisch: Leistung kann je nach Domäne variieren.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Autoencoder -->
## <h id="Type-6"> 6. Autoencoder <h>

Unüberwachte neuronale Netze, die darauf trainiert sind, ihre Eingaben zu rekonstruieren, um wichtige Merkmale zu extrahieren.

#### Stärken:

+ Dimensionsreduktion: Komprimierung von Daten auf wesentliche Merkmale.<br>
+ Merkmalsextraktion: Identifizierung wichtiger Eigenschaften in Daten.<br>
+ Anomalieerkennung: Erkennung von Abweichungen durch Rekonstruktionsfehler.<br>

#### Schwächen:

+ Überanpassung: Gefahr, triviale Identitätsfunktionen zu lernen.<br>
+ Generalisierung: Kann Schwierigkeiten haben, auf unbekannte Daten zu verallgemeinern.<br>
+ Abstimmung: Erfordert sorgfältige Hyperparameter-Optimierung.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GANs -->
## <h id="Type-7"> 7. Generative Adversarial Networks (GANs) <h>

Bestehen aus zwei Netzen – einem Generator und einem Diskriminator – die gegeneinander antreten, um realistische Daten zu erzeugen.

#### Stärken:

+ Datenaugmentation: Generierung realistischer synthetischer Daten.<br>
+ Kreativität: Anwendung in Kunst, Design und Stiltransfer.<br>
+ Innovation: Führend in der Forschung zu generativen Modellen.<br>

#### Schwächen:

+ Instabiles Training: Empfindlich gegenüber Hyperparametern und Architektur.<br>
+ Modus-Kollaps: Generator produziert wenig Vielfalt.<br>
+ Komplexität: Schwierige Implementierung und Fehlerbehebung.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Transformer -->
## <h id="Type-8"> 8. Transformer <h>

Nutzen Selbstaufmerksamkeitsmechanismen, um sequentielle Daten ohne Rekurrenz zu verarbeiten.

#### Stärken:

+ Paralleles Processing: Schnellere Trainingszeiten durch gleichzeitige Verarbeitung.<br>
+ Leistungsfähigkeit: State-of-the-Art in vielen NLP-Aufgaben.<br>
+ Lange Abhängigkeiten: Effektives Modellieren von Beziehungen über große Distanzen.<br>

#### Schwächen:

+ Speicherbedarf: Hoher Ressourcenverbrauch, insbesondere bei langen Sequenzen.<br>
+ Datenbedarf: Erfordern große Mengen an Trainingsdaten.<br>
+ Überanpassung: Risiko bei begrenzten Datenmengen.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GNN -->
## <h id="Type-9"> 9. Graph Neuronale Netze (GNN) <h>

Verarbeiten Daten, die als Graphen strukturiert sind, und modellieren Beziehungen zwischen Knoten.

#### Stärken:

+ Strukturelles Lernen: Erfassen komplexer Interaktionen in Netzwerken.<br>
+ Anwendungsbreite: Nützlich in Chemie, Sozialwissenschaften und Empfehlungssystemen.<br>
+ Flexibilität: Anpassbar an unterschiedliche Graphstrukturen.<br>

#### Schwächen:

+ Rechenaufwand: Skalierungsprobleme bei großen Graphen.<br>
+ Komplexität: Herausfordernde Implementierung und Verständnis.<br>
+ Datenverfügbarkeit: Benötigen spezialisierte Daten.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- SOMs -->
## <h id="Type-10"> 10. Selbstorganisierende Karten (SOMs) <h>

Unüberwachte Netze, die hochdimensionale Daten auf niedrigdimensionale Darstellungen abbilden.

#### Stärken:

+ Visualisierung: Erleichtern das Verständnis komplexer Daten.<br>
+ Clusterbildung: Automatische Gruppierung ähnlicher Datenpunkte.<br>
+ Unüberwacht: Keine gelabelten Daten erforderlich.<br>

#### Schwächen:

+ Skalierbarkeit: Leistungseinbußen bei sehr großen Datensätzen.<br>
+ Genauigkeit: Weniger präzise als überwachte Methoden.<br>
+ Anwendungsbereich: Eingeschränkte Einsatzgebiete in der Praxis.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Bolzmann -->
## <h id="Type-11"> 11. Boltzmann-Maschinen <h>

Stochastische Netze, die Energiezustände zur Modellierung von Wahrscheinlichkeitsverteilungen nutzen.

#### Stärken:

+ Unüberwachtes Lernen: Finden verborgener Muster ohne Labels.<br>
+ Tiefe Strukturen: Grundlage für Deep Belief Networks.<br>
+ Probabilistisches Modellieren: Erfassen komplexer Datenverteilungen.<br>

#### Schwächen:

+ Training: Sehr rechenintensiv und langsam.<br>
+ Komplexität: Schwierige Implementierung und Konvergenz.<br>
+ Anwendung: Weniger gebräuchlich in aktuellen Anwendungen.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Hpfield -->
## <h id="Type-12"> 12. Hopfield-Netze <h>

Netzwerke, die als assoziativer Speicher dienen und stabile Zustände für gespeicherte Muster haben.

#### Stärken:

+ Gedächtnisfunktion: Wiederherstellung von Mustern aus unvollständigen Eingaben.<br>
+ Stabilität: Konvergieren zu einem stabilen Zustand.<br>
+ Einfachheit: Konzeptuell einfach zu verstehen.<br>
<br>
#### Schwächen:

+ Begrenzte Kapazität: Nur wenige Muster können zuverlässig gespeichert werden.<br>
+ Spurious States: Existenz unerwünschter stabiler Zustände.<br>
+ Veraltet: Selten in modernen Anwendungen verwendet.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Capsulte -->
## <h id="Type-13"> 13. Capsule Networks <h>

Netzwerke, die Kapseln nutzen, um hierarchische Beziehungen und Orientierungen in Daten zu modellieren.

#### Stärken:

+ Hierarchisches Verständnis: Erfassen von Teil-Ganzes-Beziehungen.<br>
+ Robustheit: Bessere Leistung bei variierenden Blickwinkeln und Positionen.<br>
+ Innovation: Neuer Ansatz zur Verbesserung von CNNs.<br>
#### Schwächen:

+ Rechenintensiv: Höherer Aufwand als herkömmliche CNNs.<br>
+ Unreife Technologie: Begrenzte praktische Anwendungen bisher.<br>
+ Komplexität: Schwieriger zu trainieren und zu optimieren.<br>

<p align="right">(<a href="#top">back to top</a>)</p>

