#ifndef LIBRO_H
#define LIBRO_H

struct tComic{
    char titulo[50];
    char protagonista[30];
    char guionista[30];
    int anioPublicacion;
};

void crearComic(tComic & c);
/*
{PRE: }
{POST: Devuelve un tComic con los datos que se han introducido por pantalla}
*/

void tituloComic(tComic & c, char titulo[]);
/*
{PRE: c tiene que ser un comic que ya haya sido creado}
{POST: copia el contendio de c.titulo a titulo}
*/

void mostrarComic(tComic & c);
/*
{PRE: tcomic es un comic que ya ha sido creado}
{POST: muestra el contenido de tComic por pantalla}
*/

void copiarComic (tComic & c, tComic & cc);
/*
{PRE: tComic es un comic que ya ha sido creado}
{POST: Se copian todos los datos de c a cc}
*/


#endif /* LIBRO_H */