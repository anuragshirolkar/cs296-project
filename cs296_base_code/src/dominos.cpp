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


#include "cs296_base.hpp"
#include "render.hpp"

#ifdef __APPLE__
	#include <GLUT/glut.h>
#else
	#include "GL/freeglut.h"
#endif
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

#include "dominos.hpp"

namespace cs296
{
  /**  The is the constructor 
   * This is the documentation block for the constructor.
   */ 
	
  dominos_t::dominos_t()
  {
    //Ground
    /*! \var b1 
     * \brief pointer to the body ground 
     
    b2Body* b1;  
    {
      
      b2EdgeShape shape; 
      shape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(90.0f, 0.0f));
      b2BodyDef bd; 
      b1 = m_world->CreateBody(&bd); 
      b1->CreateFixture(&shape, 0.0f);
    }
        
    //Top horizontal shelf
    {
      b2PolygonShape shape;
      shape.SetAsBox(6.0f, 0.25f);
	
      b2BodyDef bd;
      bd.position.Set(-31.0f, 30.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }

    //Dominos
    {
      b2PolygonShape shape;
      shape.SetAsBox(0.1f, 1.0f);
	
      b2FixtureDef fd;
      fd.shape = &shape;
      fd.density = 20.0f;
      fd.friction = 0.1f;
		
      for (int i = 0; i < 10; ++i)
	{
	  b2BodyDef bd;
	  bd.type = b2_dynamicBody;
	  bd.position.Set(-35.5f + 1.0f * i, 31.25f);
	  b2Body* body = m_world->CreateBody(&bd);
	  body->CreateFixture(&fd);
	}
    }
      
    //Another horizontal shelf
    {
      b2PolygonShape shape;
      shape.SetAsBox(7.0f, 0.25f, b2Vec2(-20.f,20.f), 0.0f);
	
      b2BodyDef bd;
      bd.position.Set(1.0f, 6.0f);
      b2Body* ground = m_world->CreateBody(&bd);
      ground->CreateFixture(&shape, 0.0f);
    }


    //The pendulum that knocks the dominos off
    {
      b2Body* b2;
      {
	b2PolygonShape shape;
	shape.SetAsBox(0.25f, 1.5f);
	  
	b2BodyDef bd;
	bd.position.Set(-36.5f, 28.0f);
	b2 = m_world->CreateBody(&bd);
	b2->CreateFixture(&shape, 10.0f);
      }
	
      b2Body* b4;
      {
	b2PolygonShape shape;
	shape.SetAsBox(0.25f, 0.25f);
	  
	b2BodyDef bd;
	bd.type = b2_dynamicBody;
	bd.position.Set(-40.0f, 33.0f);
	b4 = m_world->CreateBody(&bd);
	b4->CreateFixture(&shape, 2.0f);
      }
 
      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(-37.0f, 40.0f);
      jd.Initialize(b2, b4, anchor);
      m_world->CreateJoint(&jd);
    }
      
    //The train of small spheres
    {
      b2Body* spherebody;
	
      b2CircleShape circle;
      circle.m_radius = 0.5;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 1.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
	
      for (int i = 0; i < 10; ++i)
	{
	  b2BodyDef ballbd;
	  ballbd.type = b2_dynamicBody;
	  ballbd.position.Set(-22.2f + i*1.0, 26.6f);
	  spherebody = m_world->CreateBody(&ballbd);
	  spherebody->CreateFixture(&ballfd);
	}
    }

    //The pulley system
    {
      b2BodyDef *bd = new b2BodyDef;
      bd->type = b2_dynamicBody;
      bd->position.Set(-10,15);
      bd->fixedRotation = true;
      
      //The open box
      b2FixtureDef *fd1 = new b2FixtureDef;
      fd1->density = 10.0;
      fd1->friction = 0.5;
      fd1->restitution = 0.f;
      fd1->shape = new b2PolygonShape;
      b2PolygonShape bs1;
      bs1.SetAsBox(2,0.2, b2Vec2(0.f,-1.9f), 0);
      fd1->shape = &bs1;
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 10.0;
      fd2->friction = 0.5;
      fd2->restitution = 0.f;
      fd2->shape = new b2PolygonShape;
      b2PolygonShape bs2;
      bs2.SetAsBox(0.2,2, b2Vec2(2.0f,0.f), 0);
      fd2->shape = &bs2;
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 10.0;
      fd3->friction = 0.5;
      fd3->restitution = 0.f;
      fd3->shape = new b2PolygonShape;
      b2PolygonShape bs3;
      bs3.SetAsBox(0.2,2, b2Vec2(-2.0f,0.f), 0);
      fd3->shape = &bs3;
       
      b2Body* box1 = m_world->CreateBody(bd);
      box1->CreateFixture(fd1);
      box1->CreateFixture(fd2);
      box1->CreateFixture(fd3);

      //The bar
      bd->position.Set(10,15);	
      fd1->density = 34.0;	  
      b2Body* box2 = m_world->CreateBody(bd);
      box2->CreateFixture(fd1);

      // The pulley joint
      b2PulleyJointDef* myjoint = new b2PulleyJointDef();
      b2Vec2 worldAnchorOnBody1(-10, 15); // Anchor point on body 1 in world axis
      b2Vec2 worldAnchorOnBody2(10, 15); // Anchor point on body 2 in world axis
      b2Vec2 worldAnchorGround1(-10, 20); // Anchor point for ground 1 in world axis
      b2Vec2 worldAnchorGround2(10, 20); // Anchor point for ground 2 in world axis
      float32 ratio = 1.0f; // Define ratio
      myjoint->Initialize(box1, box2, worldAnchorGround1, worldAnchorGround2, box1->GetWorldCenter(), box2->GetWorldCenter(), ratio);
      m_world->CreateJoint(myjoint);
    }

    //The revolving horizontal platform
    {
      b2PolygonShape shape;
      shape.SetAsBox(2.2f, 0.2f);
	
      b2BodyDef bd;
      bd.position.Set(14.0f, 14.0f);
      bd.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd);
      b2FixtureDef *fd = new b2FixtureDef;
      fd->density = 1.f;
      fd->shape = new b2PolygonShape;
      fd->shape = &shape;
      body->CreateFixture(fd);

      b2PolygonShape shape2;
      shape2.SetAsBox(0.2f, 2.0f);
      b2BodyDef bd2;
      bd2.position.Set(14.0f, 16.0f);
      b2Body* body2 = m_world->CreateBody(&bd2);

      b2RevoluteJointDef jointDef;
      jointDef.bodyA = body;
      jointDef.bodyB = body2;
      jointDef.localAnchorA.Set(0,0);
      jointDef.localAnchorB.Set(0,0);
      jointDef.collideConnected = false;
      m_world->CreateJoint(&jointDef);
    }

    //The heavy sphere on the platform
    {
      b2Body* sbody;
      b2CircleShape circle;
      circle.m_radius = 1.0;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 50.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;
      b2BodyDef ballbd;
      ballbd.type = b2_dynamicBody;
      ballbd.position.Set(14.0f, 18.0f);
      sbody = m_world->CreateBody(&ballbd);
      sbody->CreateFixture(&ballfd);
    }


    //The see-saw system at the bottom
    {
      //The triangle wedge
      b2Body* sbody;
      b2PolygonShape poly;
      b2Vec2 vertices[3];
      vertices[0].Set(-1,0);
      vertices[1].Set(1,0);
      vertices[2].Set(0,1.5);
      poly.Set(vertices, 3);
      b2FixtureDef wedgefd;
      wedgefd.shape = &poly;
      wedgefd.density = 10.0f;
      wedgefd.friction = 0.0f;
      wedgefd.restitution = 0.0f;
      b2BodyDef wedgebd;
      wedgebd.position.Set(30.0f, 0.0f);
      sbody = m_world->CreateBody(&wedgebd);
      sbody->CreateFixture(&wedgefd);

      //The plank on top of the wedge
      b2PolygonShape shape;
      shape.SetAsBox(15.0f, 0.2f);
      b2BodyDef bd2;
      bd2.position.Set(30.0f, 1.5f);
      bd2.type = b2_dynamicBody;
      b2Body* body = m_world->CreateBody(&bd2);
      b2FixtureDef *fd2 = new b2FixtureDef;
      fd2->density = 1.f;
      fd2->shape = new b2PolygonShape;
      fd2->shape = &shape;
      body->CreateFixture(fd2);

      b2RevoluteJointDef jd;
      b2Vec2 anchor;
      anchor.Set(30.0f, 1.5f);
      jd.Initialize(sbody, body, anchor);
      m_world->CreateJoint(&jd);

      //The light box on the right side of the see-saw
      b2PolygonShape shape2;
      shape2.SetAsBox(2.0f, 2.0f);
      b2BodyDef bd3;
      bd3.position.Set(40.0f, 2.0f);
      bd3.type = b2_dynamicBody;
      b2Body* body3 = m_world->CreateBody(&bd3);
      b2FixtureDef *fd3 = new b2FixtureDef;
      fd3->density = 0.01f;
      fd3->shape = new b2PolygonShape;
      fd3->shape = &shape2;
      body3->CreateFixture(fd3);
      }*/


		/*
		{
			b2BodyDef myBodyDef;
      myBodyDef.type = b2_staticBody;
      myBodyDef.position.Set(0, 0);
      b2Body* staticBody = m_world->CreateBody(&myBodyDef);
  
      //shape definition
      b2PolygonShape polygonShape;
    
      //fixture definition
      b2FixtureDef myFixtureDef;
      myFixtureDef.shape = &polygonShape;
      
      //add four walls to the static body
      polygonShape.SetAsBox( 20, 1, b2Vec2(0, 0), 0);//ground
      staticBody->CreateFixture(&myFixtureDef);
      polygonShape.SetAsBox( 20, 1, b2Vec2(0, 40), 0);//ceiling
      staticBody->CreateFixture(&myFixtureDef);
      polygonShape.SetAsBox( 1, 20, b2Vec2(-20, 20), 0);//left wall
      staticBody->CreateFixture(&myFixtureDef);
      polygonShape.SetAsBox( 1, 20, b2Vec2(20, 20), 0);//right wall
      staticBody->CreateFixture(&myFixtureDef);
			
		}
		{
			b2BodyDef plank;
			plank.fixedRotation = true;
			plank.type = b2_dynamicBody;
			plank.position.Set(0,0);
			b2Body* plankBody = m_world->CreateBody(&plank);

			//shape Definition
			b2PolygonShape plankShape;

			//fixture definition
			b2FixtureDef plankFixture;
			plankFixture.density = 0.5f;
			plankFixture.shape = &plankShape;
			plankShape.SetAsBox(19, 3, b2Vec2(0,25),0);
			plankBody->CreateFixture(&plankFixture);
		}
		
		{
      b2Body* spherebody;;
      b2CircleShape circle;
      circle.m_radius = 0.5;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 0.3f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 1.0f;
	
      for (int i = 0; i < 50; ++i)
			{
				b2BodyDef ballbd;
				ballbd.type = b2_dynamicBody;
				ballbd.position.Set(-12.2f + i*0.05, 16.6f);
				spherebody = m_world->CreateBody(&ballbd);
				spherebody->CreateFixture(&ballfd);
				spherebody->SetLinearVelocity( b2Vec2( rand()/10000000, rand()/10000000 ) );
			}
			}*/

		//FIXED PARTS OF THE ENGINE'S BODY
		{
						
		  b2Body* enbd1;
      b2PolygonShape poly1;
      b2Vec2 vertices1[6];
      vertices1[0].Set(9,17);
      vertices1[1].Set(9,20);
      vertices1[2].Set(13,23);
      vertices1[3].Set(28,23);
			vertices1[4].Set(32,20);
      vertices1[5].Set(32,17);
      poly1.Set(vertices1, 6);
      b2FixtureDef enfd1;
      enfd1.shape = &poly1;
      enfd1.density = 10.0f;
      enfd1.friction = 0.0f;
      enfd1.restitution = 0.0f;
      b2BodyDef enbddf1;
      enbddf1.position.Set(0.0f, 0.0f);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			

			
      b2Vec2 vertices2[4];
			vertices2[0].Set(13,23);
			vertices2[1].Set(13,26);
			vertices2[2].Set(28,26);
			vertices2[3].Set(28,23);
      poly1.Set(vertices2, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices3[4];
			vertices3[0].Set(0,0);
			vertices3[1].Set(0,26);
			vertices3[2].Set(4,26);
			vertices3[3].Set(4,4);
      poly1.Set(vertices3, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices4[3];
			vertices4[0].Set(4,23);
			vertices4[1].Set(4,26);
			vertices4[2].Set(8,26);
      poly1.Set(vertices4, 3);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices5[4];
			vertices5[0].Set(1,26);
			vertices5[1].Set(1,29);
			vertices5[2].Set(4,29);
			vertices5[3].Set(4,26);
      poly1.Set(vertices5, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices6[4];
			vertices6[0].Set(0,0);
			vertices6[1].Set(4,4);
			vertices6[2].Set(37,4);
			vertices6[3].Set(47,0);
      poly1.Set(vertices6, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices7[4];
			vertices7[0].Set(37,4);
			vertices7[1].Set(37,9);
			vertices7[2].Set(47,9);
			vertices7[3].Set(47,0);
      poly1.Set(vertices7, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices8[4];
			vertices8[0].Set(37,12);
			vertices8[1].Set(37,26);
			vertices8[2].Set(47,26);
			vertices8[3].Set(47,12);
      poly1.Set(vertices8, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices9[3];
			vertices9[0].Set(37,23);
			vertices9[1].Set(33,26);
			vertices9[2].Set(37,26);
      poly1.Set(vertices9, 3);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices10[4];
			vertices10[0].Set(37,26);
			vertices10[1].Set(37,29);
			vertices10[2].Set(40,29);
			vertices10[3].Set(40,26);
      poly1.Set(vertices10, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices11[4];
			vertices11[0].Set(1,31);
			vertices11[1].Set(1,36);
			vertices11[2].Set(4,36);
			vertices11[3].Set(4,31);
      poly1.Set(vertices11, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices12[4];
			vertices12[0].Set(4,34);
			vertices12[1].Set(4,44);
			vertices12[2].Set(5,44);
			vertices12[3].Set(5,34);
      poly1.Set(vertices12, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices13[4];
			vertices13[0].Set(37,31);
			vertices13[1].Set(37,36);
			vertices13[2].Set(40,36);
			vertices13[3].Set(40,31);
      poly1.Set(vertices13, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices14[4];
			vertices14[0].Set(36,34);
			vertices14[1].Set(36,44);
			vertices14[2].Set(37,44);
			vertices14[3].Set(37,34);
      poly1.Set(vertices14, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);
			
			b2Vec2 vertices15[4];
			vertices15[0].Set(8,34);
			vertices15[1].Set(8,44);
			vertices15[2].Set(9,44);
			vertices15[3].Set(9,34);
      poly1.Set(vertices15, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);


			
			b2Vec2 vertices16[4];
			vertices16[0].Set(8,34);
			vertices16[1].Set(8,36);
			vertices16[2].Set(18,36);
			vertices16[3].Set(18,34);
      poly1.Set(vertices16, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);
			

			
			b2Vec2 vertices17[4];
			vertices17[0].Set(18,34);
			vertices17[1].Set(18,44);
			vertices17[2].Set(19,44);
			vertices17[3].Set(19,34);
      poly1.Set(vertices17, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);
			
			b2Vec2 vertices18[4];
			vertices18[0].Set(22,34);
			vertices18[1].Set(22,44);
			vertices18[2].Set(23,44);
			vertices18[3].Set(23,34);
      poly1.Set(vertices18, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices19[4];
			vertices19[0].Set(23,34);
			vertices19[1].Set(23,36);
			vertices19[2].Set(32,36);
			vertices19[3].Set(32,34);
      poly1.Set(vertices19, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices20[4];
			vertices20[0].Set(32,34);
			vertices20[1].Set(32,44);
			vertices20[2].Set(33,44);
			vertices20[3].Set(33,34);
      poly1.Set(vertices20, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			
			
		}

		//PISTON AT THE BOTTOM
		{
			b2Body *b1;
			b2EdgeShape gshape; 
      gshape.Set(b2Vec2(-90.0f, 0.0f), b2Vec2(90.0f, 0.0f));
      b2BodyDef gbd; 
      b1 = m_world->CreateBody(&gbd); 
      b1->CreateFixture(&gshape, 0.0f);

			//BODY DEFINITIONS
			/*b2Body *piston1, *piston2; //parts of the lower piston
			b2Body *piston3, *piston4, *piston5; //parts of the upper piston
			b2Body *shaft1 ,*shaft2, *shaft3, *shaft4; //four blue shafts
			b2Body *wheel1, *wheel2, *wheel3; //three wheels
			b2Body *crank1, *crank2; //two cranks
			b2Body *pt1, *pt2, *pt3, *pt4; //fixed points around which wheels and crank rotates*/
			
			b2PolygonShape shape;
			b2FixtureDef f;
			f.filter.groupIndex = -1;
			f.shape = &shape;
			f.density = 0.1f;
			
      shape.SetAsBox(24.0f, 1.5f);
	
      b2BodyDef bd;
			bd.type = b2_dynamicBody;
      bd.position.Set(29.0f, 10.5f);
      piston1 = m_world->CreateBody(&bd);
      piston1->CreateFixture(&f);

			shape.SetAsBox(1.5f, 6.4f);
			bd.position.Set(7.5f, 10.5f);
			piston2 = m_world->CreateBody(&bd);
			piston2->CreateFixture(&f);

			b2WeldJointDef jd;
			b2Vec2 anchor(7.5f, 10.5f);
			jd.Initialize(piston1, piston2, anchor);
			m_world->CreateJoint(&jd);
		
			
			
      shape.SetAsBox(29.0f, 1);
	
      
      bd.position.Set(18.0f, 30.0f);
      piston3 = m_world->CreateBody(&bd);
      piston3->CreateFixture(&f);

			shape.SetAsBox(1.5f, 3.9f);
			bd.position.Set(9.5f, 30.0f);
			piston4 = m_world->CreateBody(&bd);
			piston4->CreateFixture(&f);

			b2WeldJointDef jd1;
			b2Vec2 anchor1(9.5f, 30.0f);
			jd1.Initialize(piston3, piston4, anchor1);
			m_world->CreateJoint(&jd1);

			shape.SetAsBox(1.5f, 3.9f);
			bd.position.Set(26.5f, 30.0f);
			piston5 = m_world->CreateBody(&bd);
			piston5->CreateFixture(&f);

			b2WeldJointDef jd2;
			b2Vec2 anchor2(26.5f, 30.0f);
			jd2.Initialize(piston3, piston5, anchor2);
			m_world->CreateJoint(&jd2);

			bd.position.Set(62, 10.5);
			shape.SetAsBox(10, 1.5);
			shaft1 = m_world->CreateBody(&bd);
			shaft1->CreateFixture(&f);

			b2RevoluteJointDef rjd1;
			b2Vec2 anchor3(52.5f, 10.5f);
			rjd1.Initialize(piston1, shaft1, anchor3);
			m_world->CreateJoint(&rjd1);

			b2MouseJointDef mjd1;
			mjd1.bodyA = b1;
			mjd1.bodyB = piston1;
			mjd1.target.Set(7.5f, 10.5f);
			m_world->CreateJoint(&mjd1);
			
			
		}


		
		/*
		{
	
      b2CircleShape circle;
      circle.m_radius = 0.5;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 1.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.0f;

			for (int i = 0; i < 10; i++) {
				b2BodyDef ballbd;
				cout << "here "<<i << endl;
				ballbd.type = b2_dynamicBody;
				ballbd.position.Set(-22.2f+i, 26.6f);
				spherebody[i] = m_world->CreateBody(&ballbd);
				spherebody[i]->CreateFixture(&ballfd);
			}

			
			}*/
		
  }

  sim_t *sim = new sim_t("Dominos", dominos_t::create);
	void dominos_t::step(settings_t* settings){
		base_sim_t::step(settings);

		
	}
}

