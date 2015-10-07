# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
	Custom/Transmogrification.h
	Custom/Transmogrification.cpp
	Custom/Transmogrifier.cpp
	Custom/utility_commandscript.cpp
	Custom/npc_arena1v1.cpp
    Custom/npc_arena1v1.h
	Custom/phased_dueling.cpp
    Custom/Arena_Spectator.cpp
	Custom/Beastmaster.cpp
	Custom/item_repair.cpp
	Custom/LearnAll.cpp
	Custom/Duel_Reset.cpp
	Custom/Reforging.cpp
	Custom/enchant_visuals.cpp
	Custom/killstreak.cpp
	Custom/lotto.cpp
	Custom/npc_token.cpp
	Custom/npc_profession.cpp
	Custom/demetria.cpp
	Custom/3v3/npc_solo3v3.cpp
	Custom/3v3/npc_solo3v3.h
	Custom/mall/guid_ally.cpp
	Custom/mall/guid_hord.cpp
	Custom/TemplateNPC.cpp
	Custom/TemplateNPC.h
)

message("  -> Prepared: Custom")
