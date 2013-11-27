/**
* This work is distributed under the General Public License,
* see LICENSE for details
*
* @author Fr�d�ric BERTOLUS
**/

#include "Game/bullet.hpp"
#include "Game/weapon.hpp"


/*----------------------------------------------
	Class definitions
----------------------------------------------*/
	
Bullet::Bullet(Game* g, String name, Weapon* parent, Vector3 location, Quaternion rotation, Vector3 velocity)
	//: MeshActor(g, name, "SM_Exhaust.mesh", "MI_Exhaust", false, 1.0)
	: MeshActor(g, name, "SM_Bullet.mesh", "MI_Gloss", false, 0.0001)
{
	
	mLifeTime = 0;
	mTimeToLive = 10;
	
	// Customization
	
	//customize(1000, 2.0, 0.1f);

	// Position
	mWeapon = (Weapon*)parent;
	rotate(rotation);
	setLocation(location);
	setSpeed(velocity);
}


void Bullet::tick(const Ogre::FrameEvent& evt)
{
	mLifeTime += evt.timeSinceLastFrame;
	
	if(mLifeTime > mTimeToLive) {
		// TODO make destroy
		// delete this;
	}
}

