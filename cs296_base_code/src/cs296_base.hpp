/*
* Copyright (c) 2006-2009 Erin Catto http://www.box2d.org
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

/* 
 * Base code for CS 296 Software Systems Lab 
 * Department of Computer Science and Engineering, IIT Bombay
 * Instructor: Parag Chaudhuri
 */


#ifndef _CS296BASE_HPP_
#define _CS296BASE_HPP_

#include "render.hpp"
#include <Box2D/Box2D.h>
#include <cstdlib>

#define	RAND_LIMIT 32767

namespace cs296
{

  //! The difference between a class and struct is the access to its elements;<br>
  //! struct:always public;class:default private canbe changed to public and protected<br><br>
  class base_sim_t;
  struct settings_t;
  
  //! Why do we use a typedef:We use a typedef as it helps with defining complex  expressions<br>
  //! and we do not have to edit the expression everywhere. < br><br>  
  typedef base_sim_t* sim_create_fcn(); 

  /** \brief This class deals with Simulation settings especially those  of the debug_draw and m_world <br>
  * some of which can be controlled in the GUI.It ensures that overlappings don't occur,drawing flags are set etc. <br><br>
  * A brief description of the members: <br><br>
  * hz=60.0 fps is basically used for assigning the timeskip <br><br> 
  * The velocity and step iterations are only relevant to collision resolution. < br>
  * They help in preventing any kind of overlap. <br> <br>
  * draw_shapes,draw_joints,draw_AABBs,draw_pairs and draw_COMs are draw flags for m_debug_draw <br><br>
  * draw_contact* and draw_friction* are for simulation of contact forces,friction <br>
  * and other other parameters as ther name suggests. <br> <br>
  * enable_* variables are meant to to start cetain properties like warm_starting,continuity,substepping<br><br>*/
  struct settings_t
  {
    //! Notice the initialization of the class members in the constructor <br>
    //! How is this happening? <br>
    //! This is the constructor of the defined struct.The constructor function initializes all the required variables. <br>
	  
	  settings_t() :
      view_center(0.0f, 20.0f),
      hz(60.0f),
      velocity_iterations(8),
      position_iterations(3),
      draw_shapes(1),
      draw_joints(1),
      draw_AABBs(0),
      draw_pairs(0),
      draw_contact_points(0),
      draw_contact_normals(0),
      draw_contact_forces(0),
      draw_friction_forces(0),
      draw_COMs(0),
      draw_stats(0),
      draw_profile(0),
      enable_warm_starting(1),
      enable_continuous(1),
      enable_sub_stepping(0),
      pause(0),
      single_step(0)
    {}
    
    b2Vec2 view_center;//!<type:b2Vec2;  tells us the Graphical User interface (GUI) centre
    float32 hz;//!< type:float32; hz refers to frequency of iterations ...used for timeskip
    int32 velocity_iterations;//!< type:int32;  Changes the velocity , to correct collisions,for example <br>
			      //!   make sure that a ball bounces off a wall correctly, or to make<br>
			      //! something rotate if it is hit off-center.<br>
    int32 position_iterations;//!< type:int32; This ensures no overlap during the collision
    int32 draw_shapes;//!< type:int32; Draw flag for e_shapeBit: used for drawing shapes
    int32 draw_joints;//!< type:int32; Draw flag for e_jointBit: used for drawing joint connections
    int32 draw_AABBs;//!< type:int32; Draw flag for e_aabbBit: used for drawing axis aligned bounding boxes
    int32 draw_pairs;//!< type:int32; Draw flag for e_pairBit: used for drawing broad-phase pairs
    int32 draw_contact_points;//!< type:int32; nature:boolean; Asks debug_draw to drawpoint set the contact points
    int32 draw_contact_normals;//!< type:int32; nature:boolean; Asks debug_draw to draw segment along normal
    int32 draw_contact_forces;//!< type:int32; nature:bolean; Used for application of forces on bodies at<br>
						      //! times of collision or contact
    int32 draw_friction_forces;//!< type:int32; nature:boolean; Applies friction on bodies in contact given<br>
							   //! to debug_draw to drawsegment along tangent.  
    int32 draw_COMs;//!< type:int32; Draw flag for b2Draw::e_centerOfMassBit:used for drawing center of mass frame
    int32 draw_stats;//!< type:int32: it shows more info about joints , contacts and bodies. 
    int32 draw_profile;//!< type:int32; shows all the calculations 
    int32 enable_warm_starting;//!<type:int32; helps in using the previous timestep info for next one for accuracy
    int32 enable_continuous;//!<type:int32; nature:boolean;enables continuous physics though the box2D runs in discretesteps<br> 
							//!it ensures that bodies don't pass through each other.
    int32 enable_sub_stepping;//!<type:int32; nature:boolean; Enable/disable single stepped continuous physics. For testing. 
    int32 pause;//!< type:int32 ; used for pausing the simulation
    int32 single_step;//!< type:int32 ; variable helps in stepping one by one to the end of the simulation
  };
  

/**\brief The Struct sim_t is using the typedef to create an instance of an object of the class  base_sim_t(dominos_t).
  * <br> It also stores a string as a corresponding reference  or for  referring purposes. */
  struct sim_t
  {
    const char *name;//!<name of reference or the name of simulation
    sim_create_fcn *create_fcn;//!<used typedef instance of the class base_sim_t
  //!constructor for the struct assigns the corresponding values
    sim_t(const char *_name, sim_create_fcn *_create_fcn): 
      name(_name), create_fcn(_create_fcn) {;}
  };
  
  extern sim_t *sim; 
  
  const int32 k_max_contact_points = 2048;  //!<max no. of contact points
  
  /** \brief This struct stores the parameters for two bodies or fixtures in contact with each <br>
   * other.It is used in the pre-solve function in corresponding cpp file. The variables refer<br>
   * to the same things as their names.*/
	struct contact_point_t
  {
    b2Fixture* fixtureA;//!< Pointer to the variable containing properties of body a
    b2Fixture* fixtureB;//!< describes body b similar to body b
    b2Vec2 normal;//!< vector of the normal
    b2Vec2 position;//!< vector of position
    b2PointState state;//!< stores the state of the point
  };
  /**  
 * \brief This class is the most important data structure made.dominoes_t which is inherited from this <br>
 * defines all the objects.This also creates the world.It implements the settings we had seen in <br>
 * the struct settings_t(drawing objects,pausing,enabling features etc.).Also used in pre_solver class <br>
 * for giving the contact info.
  */
  class base_sim_t : public b2ContactListener
  {
  public:
    //! constructor of the base_sim_t class.
    base_sim_t();

    //! Virtual destructors ensure that the inherited classes destructors are also called thereby<br>
    //! deleting all the objects created.
    virtual ~base_sim_t();
    //! sets no. of line after which the debug message would appear
    void set_text_line(int32 line) { m_text_line = line; }
    //! the "string" is printed at position(x,y)
    void draw_title(int x, int y, const char *string);
    //! assigns the different m_world and m_debug_draw features 
    virtual void step(settings_t* settings);
    //! checks for key press & responds
    virtual void keyboard(unsigned char key) { B2_NOT_USED(key); }
    //! checks for key(arrow keys)  press & responds
    virtual void keyboard_up(unsigned char key) { B2_NOT_USED(key); }
    //! checks if mouse is in shift_mouse_down state and responds
    void shift_mouse_down(const b2Vec2& p) { B2_NOT_USED(p); }
    //! checks if mouse is in mouse_down state and responds
    virtual void mouse_down(const b2Vec2& p) { B2_NOT_USED(p); }
    //! checks if mouse is in mouse_up state and responds
    virtual void mouse_up(const b2Vec2& p) { B2_NOT_USED(p); }
    //! checks if mouse is in mouse_move state and responds
    void mouse_move(const b2Vec2& p) { B2_NOT_USED(p); }

    
    //! Let derived tests know that a joint was destroyed.
  virtual void joint_destroyed(b2Joint* joint) { B2_NOT_USED(joint); }
    
    //! Callbacks for derived classes.
    virtual void begin_contact(b2Contact* contact) { B2_NOT_USED(contact); }
    //! Callbacks for derived classes.
    virtual void end_contact(b2Contact* contact) { B2_NOT_USED(contact); }
    //! Callbacks for derived classes.
    virtual void pre_solve(b2Contact* contact, const b2Manifold* oldManifold);
    //! Callbacks for derived classes.
    virtual void post_solve(const b2Contact* contact, const b2ContactImpulse* impulse)
    {
      B2_NOT_USED(contact);
      B2_NOT_USED(impulse);
    }

	protected:
  //!How are protected members different from private memebers of a class in C++ ?
  //!protected nonstatic base class member can be accessed by members and friends of any classes derived from that base class

    //! What are Friend classes?
    friend class contact_listener_t;
    
    b2Body* m_ground_body;//!< defines a ground body
    b2AABB m_world_AABB;//!< stores/defines Axis aligned  bounding boxes(AABB)
    contact_point_t m_points[k_max_contact_points];//!< array to store contact points
    int32 m_point_count;//!<for count of points

    debug_draw_t m_debug_draw;//!variable which helps in drawing
    int32 m_text_line;//!max no.of lines 
    b2World* m_world;//!The world object

    int32 m_step_count;//!maintains no.of steps taken
    
    b2Profile m_max_profile;//! maximum profile definition
    b2Profile m_total_profile;//! total profile definition
	public:
		const b2World* get_world(void)
				{
						return m_world;

							}
  };
}

#endif
