/**
 * @file
 * @brief Functions with decks of cards.
**/

#pragma once

#include "enum.h"

/// The minimum number of cards a deck starts with, when generated normally.
const int MIN_STARTING_CARDS = 4;
/// The maximum number of cards a deck starts with, when generated normally.
const int MAX_STARTING_CARDS = 13;

enum deck_type
{
    DECK_OF_ESCAPE,
    DECK_OF_DESTRUCTION,
    DECK_OF_SUMMONING,
    DECK_OF_PUNISHMENT,
};

enum card_flags_type
{
                      //1 << 0
    CFLAG_SEEN       = (1 << 1),
                      //1 << 2
    CFLAG_PUNISHMENT = (1 << 3),
    CFLAG_DEALT      = (1 << 4),
};

enum card_type
{
    CARD_VELOCITY,            // remove slow, alter others' speeds
    CARD_TOMB,                // a ring of rock walls
    CARD_EXILE,               // banish others, maybe self
    CARD_SHAFT,               // under the user, maybe others
    CARD_VITRIOL,             // acid damage
    CARD_CLOUD,               // encage enemies in rings of clouds
    CARD_STORM,               // wind and rain
    CARD_PAIN,                // necromancy, manipulating life itself
    CARD_TORMENT,             // symbol of
    CARD_ORB,                 // pure bursts of energy
    CARD_ELIXIR,              // restoration of hp and mp
    CARD_SUMMON_DEMON,        // dual demons
    CARD_SUMMON_WEAPON,       // a dance partner
    CARD_SUMMON_FLYING,       // swarms from the swamp
    CARD_WILD_MAGIC,          // miscasts for everybody
    CARD_STAIRS,              // moves stairs around
    CARD_WRATH,               // random godly wrath
    CARD_WRAITH,              // drain XP
    CARD_FAMINE,              // starving
    CARD_SWINE,               // *oink*
    CARD_ILLUSION,            // a copy of the player
    CARD_DEGEN,               // polymorph hostiles down hd, malmutate
    CARD_ELEMENTS,            // primal animals of the elements
    CARD_RANGERS,             // sharpshooting
    NUM_CARDS
};

const char* card_name(card_type card);
card_type name_to_card(string name);
const string deck_contents(deck_type deck);
bool deck_triple_draw();
bool deck_deal();
string which_decks(card_type card);
bool deck_stack();

bool draw_three(int slot);
bool stack_five(int slot);

void card_effect(card_type which_card,
                 uint8_t card_flags = 0, bool tell_card = true);
void draw_from_deck_of_punishment(bool deal = false);

string deck_name(uint8_t type);

#if TAG_MAJOR_VERSION == 34
bool is_deck_type(uint8_t type);
bool is_deck(const item_def &item);
void reclaim_decks();
void reclaim_decks_on_level();
#endif
