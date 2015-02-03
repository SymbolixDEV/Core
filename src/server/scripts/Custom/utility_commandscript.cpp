#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "MapManager.h"
#include "Chat.h"
#include "Group.h"

//This script is made by Blex and was orginally posted on www.ac-web.org
//This script was created after being inspired by Arena-Tournament's player commands. www.arena-tournament.com
//Edited by Sydowh

class tools_commandscript : public CommandScript
{
public:
    tools_commandscript() : CommandScript("tools_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand toolsCommandTable[] =
        {
            { "changerace",            rbac::RBAC_PERM_COMMAND_CHANGE_RACE,  false, &HandleChangeRaceCommand,             "", NULL },
			{ "changefaction",		  rbac::RBAC_PERM_COMMAND_CHANGE_FACTION,  false, &HandleChangeFactionCommand,		"", NULL },
			{ "maxskills",			rbac::RBAC_PERM_COMMAND_MAX_SKILLS,  false, &HandleMaxSkillsCommand,		"", NULL },
			{ "customize",			rbac::RBAC_PERM_COMMAND_CUSTOMIZE,  false, &HandleCustomizeCommand,		"", NULL },
            { NULL,             0,                  false, NULL,                              "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "tools",           SEC_PLAYER,      true, NULL,                   "", toolsCommandTable },
            { NULL,             0,                  false, NULL,                               "", NULL }
        };
        return commandTable;
    }

		static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Now you can relog to change race of your character.");
        return true;
    }

		static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Now you can relog to change faction of your character.");
        return true;
    }

		static bool HandleMaxSkillsCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->UpdateSkillsForLevel();
		handler->PSendSysMessage("Now your weapon skills are now maximized.");
        return true;
    }

	static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
    {

        Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Now you can relog to customize your character.");
        return true;
    }
};

void AddSC_tools_commandscript()
{
    new tools_commandscript();
}
