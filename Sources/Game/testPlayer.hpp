/**
* This work is distributed under the General Public License,
* see LICENSE for details
*
* @author Gwenna�l ARBONA
**/

#ifndef __TESTPLAYER_H_
#define __TESTPLAYER_H_

#include "Engine/Player.hpp"


/*----------------------------------------------
	Class definitions
----------------------------------------------*/

class TestPlayer : public Player
{

public:
	
	TestPlayer(World* w, String name, SceneManager* scene) : Player(w, name, scene){}

	bool processKey(const FrameEvent& evt, OIS::Keyboard* kb);

};

#endif /* __TESTPLAYER_H_ */
