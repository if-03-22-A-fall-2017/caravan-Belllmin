/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			caravan.c
 * Author(s):		Peter Bauer
 * Due Date:		#due#
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "caravan.h"
#include "pack_animal.h"

struct NODE
{
  PackAnimal data;
  struct NODE *next;
};

struct CaravanImplementation
{
  struct NODE *head;
  int count;
};

/**
* Initialisiert eine Karawane. D. h., dass es alle in der Karawane befindlichen Tiere aus der
* Karawane entfernt und die Karawane als leer kennzeichnet.
* @param caravan Die Karawane, welche initialisiert werden soll.
*/
Caravan new_caravan()
{
  Caravan new_c = (Caravan)malloc(sizeof(struct CaravanImplementation));
  new_c->count = 0;
  return new_c;
}

/**
* @return Die Länge einer Karawane, d.h., die Anzahl der Tiere in der Karawane.
*/
int get_length(Caravan caravan)
{
  return caravan->count;
}

/**
* Entfern alle Tiere aus einer Karawane und löscht die Karawane.
*/
void delete_caravan(Caravan caravan)
{
  //sfree(caravan);
}

/**
* Fügt ein Packtier zu einer Karawane hinzu.
*/
void add_pack_animal(Caravan caravan, PackAnimal animal)
{
  if(caravan->head->data == NULL)
  {
    caravan->head->data = animal;
    caravan->count++;
  }
  else
  {
    struct NODE *current = caravan->head;
    while(current->next != NULL)
    {
      current = current->next;
    }
    current->next->data = animal;
    caravan->count++;
  }
}

/**
* Entfernt ein Packtier aus einer Karawane.
*/
void remove_pack_animal(Caravan caravan, PackAnimal animal)
{
  struct NODE *current = caravan->head;
  while(current != NULL)
  {
    if(current->data == animal)
    {
      current = current->next;
    }
    current = current->next;
  }
}

/**
* @return Die Geschwindigkeit einer Karawane. Diese richtet sich nach der Geschwindigkeit des
* langsamsten Tiers in der Karawane.
*/
int get_caravan_speed(Caravan caravan)
{
  int total_speed = 0;
  struct NODE *current = caravan->head;

  while(current != NULL)
  {
    //if(current->data->max_speed < current->next->data->max_speed)
    //{
    //  total_speed = current->data->max_speed;
    //}
    current = current->next;
  }
  return total_speed;
}

/**
* @return Die Gesamtanzahl der Ballen einer Karawane.
*/
int get_caravan_load(Caravan caravan)
{
  int total_load = 0;
  struct NODE *current = caravan->head;

  while(current != NULL)
  {
    //total_load += current->data.load;
    current = current->next;
  }
  return total_load;
}

/**
* Entl&auml;dt die gesamte Karawane. D.h. es wird jedes Tier in der Karawane von seinen Ballen
* befreit.
*/
void unload(Caravan caravan)
{
  struct NODE *current = caravan->head;
  while(current != NULL)
  {
    //current->data.load = 0;
    current = current->next;
  }
}

/**
* Verteilt die Last der Ballen so auf die einzelnen Tiere, dass die Geschwindigkeit der Karawane
* maximal ist.
*/
void optimize_load(Caravan caravan)
{

}
