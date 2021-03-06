/**
* This work is distributed under the General Public License,
* see LICENSE for details
*
* @author Gwenna�l ARBONA
**/


#ifndef __GAME_H_
#define __GAME_H_

#include "Engine/Rendering/renderer.hpp"
#include "Engine/bulletphysics.hpp"
#include "Engine/iomanager.hpp"
#include "tinyxml2.hpp"

class Actor;
class Player;
class PointLight;


/*----------------------------------------------
	Game class definition
----------------------------------------------*/

class Game : public Ogre::FrameListener
{

public:
	
	/**
	 * @brief Load the world
	 **/
	Game();

	/**
	 * @brief Unload the world
	 **/
	virtual ~Game();

	/**
	 * @brief Run the level (blocking)
	 **/
	virtual void run();
	
	/**
	 * @brief Main tick event
	 * @param evt				Frame event
	 **/
	virtual void tick(const Ogre::FrameEvent& evt);
	
	/**
	 * @brief Register an actor to the world
	 * @param ref				Actor reference
	 **/
	void registerActor(Actor* ref);
	
	/**
	 * @brief Unregister an actor to the world
	 * @param ref				Actor reference
	 **/
	void unregisterActor(Actor* ref);
	
	/**
	 * @brief Remove an actor
	 * @param target			Actor reference
	 **/
	void deleteActor(Actor* target);

	/**
	 * @brief Run the level (blocking)
	 * @param name				Node name
	 * @return the scene node
	 **/
	Ogre::SceneNode* createGameNode(String name);
	
	/**
	 * @brief Remove a scene node
	 * @param node				Node reference
	 **/
	void deleteGameNode(Ogre::SceneNode* node);
	
	/**
	 * @brief Create en entity
	 * @param name				Node name
	 * @param file				File name
	 * @return the scene entity
	 **/
	Ogre::Entity* createGameEntity(String name, String file);
	
	/**
	 * @brief Remove an entity
	 * @param entity			Entity reference
	 **/
	void deleteGameEntity(Ogre::Entity* entity);
	
	/**
	 * @brief Register a rigid body to the scene
	 * @param body				Rigid body
	 **/
	void registerRigidBody(btRigidBody* body);
	
	/**
	 * @brief Unregister a rigid body from the scene
	 * @param body				Rigid body
	 **/
	void unregisterRigidBody(btRigidBody* body);
	
	/**
	 * @brief Quit the game
	 **/
	virtual void quit();
	
	/**
	 * @brief Get the current scene manager
	 * @return the scene
	 **/
	Ogre::SceneManager* getScene();
	
	/**
	 * @brief Get the current config file root
	 * @return the root XML element
	 **/
	tinyxml2::XMLElement* getConfig();
	
	/**
	 * @brief Write text to the log file
	 * @param text				Input data
	 **/
	virtual void gameLog(String text);
 
	/**
	 * @brief Set the scene debug status
	 * @param newStatus			New state
	 **/
	virtual void setDebugMode(int newStatus);
	
	/**
	 * @brief Get a debug line to use for debugging
	 * @param line				Line vector
	 * @param name				Object unique name
	 * @param material			Material name
	 * @return a debug object
	 **/
	Ogre::ManualObject* getDebugLine(Vector3 line, String name, String material);

	/**
	 * @brief Dump all scene nodes to the log file
	 **/
	void dumpAllNodes();


protected:

	/**
	 * @brief Level construction
	 **/
	virtual void construct() = 0;

	/**
	 * @brief Level destruction
	 **/
	virtual void destruct() = 0;
	
	/**
	 * @brief Frame start event
	 **/
	bool frameRenderingQueued(const Ogre::FrameEvent& evt);
	
	/**
	 * @brief Frame stop event
	 **/
	bool frameEnded(const Ogre::FrameEvent& evt);
	
	/**
	 * @brief Setup the level
	 **/
	virtual bool setup();

	/**
	 * @brief Setup resources
	 **/
	virtual void setupResources();
	
	/**
	 * @brief Setup the render sytsem
	 * @param desiredRenderer	Render system to use
	 **/
	virtual bool setupSystem(const String desiredRenderer);

	/**
	 * @brief Setup rendering methods
	 * @param bShowPostProcess	Should show post processing
	 **/
	virtual void setupRender(bool bShowPostProcess = true);
	
	/**
	 * @brief Setup the player
	 **/
	virtual void setupPlayer();

	/**
	 * @brief Setup the physics world
	 * @param gravity			Gravity vector
	 * @param bDrawDebug		Should display hulls
	 **/
	virtual void setupPhysics(Vector3 gravity, bool bDrawDebug = false);
	
	/**
	 * @brief Dump a node to a string stream
	 * @param ss				Output stream
	 * @param n					Node
	 * @param leveln			Current recursion depth
	 * @return the scene entity
	 **/
	void dumpNodes(std::stringstream &ss, Ogre::Node *n, int level);
	

protected:


	// Is it running ?
	bool bRunning;
	
	// OGRE data
	Ogre::Root* mRoot;
	Ogre::SceneManager* mScene;
	Ogre::RenderWindow* mWindow;
	Ogre::OverlaySystem* mOverlaySystem;

	// Bullet data
	DebugDrawer* mPhysDrawer;
	btDiscreteDynamicsWorld* mPhysWorld;
	btBroadphaseInterface* mPhysBroadphase;
	btCollisionDispatcher* mPhysDispatcher;
	btDefaultCollisionConfiguration* mPhysCollisionConfiguration;
	btSequentialImpulseConstraintSolver* mPhysSequentialImpulseConstraintSolver;

	// Custom data
	Renderer* mRenderer;
	Player* mPlayer;
	IOManager* mIOManager;
	tinyxml2::XMLDocument* mConfigFile;
	tinyxml2::XMLElement* mConfig;

	Ogre::list<Actor*>::type mAllActors;
	Ogre::list<Actor*>::type mToRemoveActors;

#ifdef OGRE_STATIC_LIB
	StaticPluginLoader mStaticPluginLoader;
#endif

};

#endif /* __GAME_H_ */

