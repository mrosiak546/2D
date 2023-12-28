# 2D

# Opis
Projekt 2D jest to aplikacja umożliwiająca modyfikację obrazów 2D dostarczając prosty interfejs do przesuwania obracania skalowania oraz pochylenia.

# Funkcje
1. Presuwanie
   - Funkcja przesuwania pozwala użytkownikowi zmieniać położenie obrazu. Za pomocą suwaków które wywołują funkcję `przesuwanieDX` i `przesuwanieDY` dzięki czemu możliwe są operacje przesunięcia obrazu względem osi X i Y.
2. Obracanie
   - Funkcja ta umożliwia użytkownikowi obrót obrazu o zadany kąt. Kąt ten możemy ustalić za pomocą suwaka. Obracanie jest realizowane przez funkcje `obracanie`
3. Skalowanie
   - Skalowanie pozwala na zmianę rozmiaru obrazu wzdłuż osi X i Y. Funkcja ta jest realizowana przez funkcje `pochylenieSHX` i `pochylenieSHY`
4. Pochylanie
   - Funkcja pochylania pozwala nam na przekształcenie obrazu względem osi X i Y nadając efekt pochylenie go względem wybranej osi. Funkcje realizujące te opcje to `pochylanieSHX` i `pochylanieSHY`
5. Resetowanie
   - Przywraca nam pierwotny stan obrazu

#Użycie
1. Wgraj obrazu do programu
2. Uruchom aplkikacje
3. Wykonuj operacje na suwakach:
   - Przesuwanie
   - Obracanie
   - Skalowanie
   - Pochylanie
  Patrz na efekty wykonywanych operacji
5. Przywróć w dowolnym momencie do stanu początkowego
