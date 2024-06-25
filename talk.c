#include <stdbool.h>
#include <stdio.h>
#include "object.h"
#include "print.h"
#include "misc.h"
#include "match.h"
#include "noun.h"
#include "reach.h"

static int talk(const char *about, OBJECT *to)
{
   OBJECT *topic = getTopic(about);
   if (topic == NULL)
   {
      printPrivate("I don't understand what you want to talk about.\n");
      return 0;
   }
   else
   {
      printPrivate("You hear %s say: '%s'\n",
                   to->description,
                   topic == to ? "I don't want to talk about myself."
                               : topic->gossip);
      return 1;
   }
}

int executeTalk(void)
{
   OBJECT *to = actorHere();
   if (to != NULL)
   {
      return talk(params[0], to);
   }
   else
   {
      printPrivate("There is nobody here to talk to.\n");
      return 0;
   }
}

int executeTalkTo(void)
{
   OBJECT *to = reachableObject("who to talk to", params[1]);
   if (to != NULL)
   {
      if (to->health > 0)
      {
         return talk(params[0], to);
      }
      else
      {
         printPrivate("There is no response from %s.\n", to->description);
         return 1;
      }
   }
   return 0;
}
