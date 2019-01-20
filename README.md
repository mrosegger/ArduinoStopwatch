# stopWatch

# Aufgabenstellung

Erstellen Sie eine Binäre Stoppuhr für den Arduino-Uno.

Folgende Funktionalitäten sind zu implementieren.

1) Die Stoppuhr soll auf den LEDs 2-7 die Aktuelle Zeit binär darstellen. Bei Überlauf soll die Uhr
bei 000000 weiterlaufen.

2) Über den Button A0 ist die Uhr zu starten beziehungsweise anzuhalten.

3) Über den Button A1 ist eine Zwischenzeit zu nehmen. Die Uhr läuft im Hintergrund weiter.
Bei nochmaligem drücken des Buttons A1 ist die aktuelle (im hintergrund weitergelaufene) Zeit wieder anzuzeigen.

4) Der Button A2 hat nur im durch A0 gestoppten Zustand eine Funktion und setzt die aktuelle Zeit zurück, sodass bei
erneutem drücken von A0 die Stoppuhr wieder bei 000000 beginnt.


# Hardware 

Verwenden Sie hierzu folgende Hardware.

* Einen Arduino UNO

* Das HTL Weiz Arduino Shield

![HTL Weiz Arduino Shield](https://github.com/htlweiz/logicAndCount/blob/master/Foto%2019-01-20%2020-29-05%200418.jpg)

