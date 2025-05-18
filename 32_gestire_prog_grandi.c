/*

1) Tutte i file includono un file "padre".h contenente le varie include e deinfe e l'elenco protitipi funzioni
2) Il comando: wc READ_ME *.h *.c makefile  (word count, grande progetto sopra le centomila righe di codice)
3) Nel codice si può inserire il #include <assert.h>, esempio:
   c = f(a, b);
   assert(c > 0);
	
   => cosa fa?   se f è una funzione magari scritta da un altro programmatore ed è magari esterna pure
			     con l'assert posso FORZARE delle condizioni. 

*/