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
		n = 200;
    
		//FIXED PARTS OF THE ENGINE'S BODY
		{
						
		  b2Body* enbd1;
      b2PolygonShape poly1;
			 b2Vec2 vertices1[4];
      vertices1[0].Set(9,17);
      vertices1[1].Set(16,26);
      vertices1[2].Set(24,26);
      vertices1[3].Set(32,17);
			//vertices1[4].Set(32,20);
      //vertices1[5].Set(32,17);
      poly1.Set(vertices1, 4);
      b2FixtureDef enfd1;
      enfd1.shape = &poly1;
      enfd1.density = 10.0f;
      enfd1.friction = 0.0f;
      enfd1.restitution = 1.0f;
      b2BodyDef enbddf1;
      enbddf1.position.Set(0.0f, 0.0f);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			

			/*
      b2Vec2 vertices2[4];
			vertices2[0].Set(13,23);
			vertices2[1].Set(13,26);
			vertices2[2].Set(28,26);
			vertices2[3].Set(28,23);
      poly1.Set(vertices2, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);
			*/
			b2Vec2 vertices3[4];
			vertices3[0].Set(0,0);
			vertices3[1].Set(0,26);
			vertices3[2].Set(4,26);
			vertices3[3].Set(4,4);
      poly1.Set(vertices3, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices4[3];
			vertices4[0].Set(4,17);
			vertices4[1].Set(4,26);
			vertices4[2].Set(6.2f,26);
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
			vertices9[0].Set(37,17);
			vertices9[1].Set(35.2f,26);
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
			vertices15[0].Set(11.2f,34);
			vertices15[1].Set(11.2f,44);
			vertices15[2].Set(12.2f, 44);
			vertices15[3].Set(12.2f,34);
      poly1.Set(vertices15, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);


			
			b2Vec2 vertices16[4];
			vertices16[0].Set(12.2f,34);
			vertices16[1].Set(12.2f,36);
			vertices16[2].Set(14.4f,36);
			vertices16[3].Set(14.4f,34);
      poly1.Set(vertices16, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);
			

			
			b2Vec2 vertices17[4];
			vertices17[0].Set(14.4f,34);
			vertices17[1].Set(14.4f,44);
			vertices17[2].Set(15.4f,44);
			vertices17[3].Set(15.4f,34);
      poly1.Set(vertices17, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);
			
			b2Vec2 vertices18[4];
			vertices18[0].Set(25.6f,34);
			vertices18[1].Set(25.6f,44);
			vertices18[2].Set(26.6f,44);
			vertices18[3].Set(26.6f,34);
      poly1.Set(vertices18, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices19[4];
			vertices19[0].Set(26.6f,34);
			vertices19[1].Set(26.6f,36);
			vertices19[2].Set(28.8f,36);
			vertices19[3].Set(28.8f,34);
      poly1.Set(vertices19, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			b2Vec2 vertices20[4];
			vertices20[0].Set(28.8f,34);
			vertices20[1].Set(28.8f,44);
			vertices20[2].Set(29.8f,44);
			vertices20[3].Set(29.8f,34);
      poly1.Set(vertices20, 4);
      enbd1 = m_world->CreateBody(&enbddf1);
      enbd1->CreateFixture(&enfd1);

			
			
		}

		//PISTON AT THE BOTTOM
		{

			//BODY OBJECTS
			b2Body *piston1, *piston2; //parts of the lower piston
			b2Body *piston3, *piston4, *piston5; //parts of the upper piston
			b2Body *shaft1 ,*shaft2, *shaft3, *shaft4; //four blue shafts
			b2Body *wheel1, *wheel2, *wheel3; //three wheels
			b2Body *crank1, *crank2; //two cranks
			b2Body *pt1, *pt2, *pt3, *pt4; //fixed points around which wheels and crank rotates

			//PISTONS
			b2BodyDef pistonbd;
		  pistonbd.type = b2_dynamicBody;
			b2PolygonShape pistonShape;
			b2FixtureDef pistonFixt;
			pistonFixt.shape = &pistonShape;
			pistonFixt.density = 1.0f;
			pistonFixt.restitution = 1;
			pistonFixt.filter.groupIndex = -1;

			//SHAFTS
			b2BodyDef shaftbd;
			shaftbd.type = b2_dynamicBody;
			b2PolygonShape shaftShape;
			b2FixtureDef shaftFixt;
			shaftFixt.shape = &shaftShape;
			shaftFixt.density = 0.1f;
			shaftFixt.filter.groupIndex = -1;

			//WHEELS
			b2BodyDef wheelbd;
			wheelbd.type = b2_dynamicBody;
			b2CircleShape wheelShape;
			wheelShape.m_radius = 14;
			b2FixtureDef wheelFixt;
			wheelFixt.shape = &wheelShape;
			wheelFixt.density = 20.0f;
			wheelFixt.filter.groupIndex = -1;

			//CRANKS
			b2BodyDef crankbd;
			crankbd.type = b2_dynamicBody;
			b2PolygonShape crankShape;
			b2FixtureDef crankFixt;
			crankFixt.shape = &crankShape;
			crankFixt.density = 0.1f;
			crankFixt.filter.groupIndex = -1;

			//FIXED POINTS
			b2BodyDef ptbd;
			
		
			//PISTON1
			pistonFixt.filter.categoryBits = 0x0001;
			pistonFixt.filter.maskBits = 0xFFFF & ~0x0002;
      pistonShape.SetAsBox(24.0f, 1.5f);
      pistonbd.position.Set(29.0f, 10.5f);
      piston1 = m_world->CreateBody(&pistonbd);
      piston1->CreateFixture(&pistonFixt);

			//PISTON2
			pistonFixt.filter.categoryBits = 0x0003;
			pistonFixt.filter.maskBits = 0xFFFF;
			pistonShape.SetAsBox(2.0f, 6.4f);
			pistonbd.position.Set(9.5f, 10.5f);
			pistonFixt.restitution = 0;
			pistonFixt.filter.groupIndex = -2;
			piston2 = m_world->CreateBody(&pistonbd);
			piston2->CreateFixture(&pistonFixt);

			//WELDJOINT BETWEEN PISTON1 AND PISTON2
			b2WeldJointDef jd;
			b2Vec2 anchor(7.5f, 10.5f);
			jd.Initialize(piston1, piston2, anchor);
			m_world->CreateJoint(&jd);
		
			
			//PISTON3
      pistonShape.SetAsBox(29.0f, 1);
      pistonbd.position.Set(18.0f, 30.0f);
			
			pistonFixt.restitution = 1;
			//pistonFixt.filter.groupIndex = -1;
			pistonFixt.filter.categoryBits = 0x0001;
			pistonFixt.filter.maskBits = 0xFFFF & ~0x0002;
      piston3 = m_world->CreateBody(&pistonbd);
      piston3->CreateFixture(&pistonFixt);

			//PISTON4
			pistonShape.SetAsBox(3.1f, 3.9f);
			pistonbd.position.Set(11.2f, 30.0f);
			//pistonFixt.filter.groupIndex = -2;
			pistonFixt.filter.categoryBits = 0x0003;
			pistonFixt.filter.maskBits = 0xFFFF;
			piston4 = m_world->CreateBody(&pistonbd);
			piston4->CreateFixture(&pistonFixt);

			//WELDJOINT BETWEEN PISTON3 AND PISTON4
			b2WeldJointDef jd1;
			b2Vec2 anchor1(11.2f, 30.0f);
			jd1.Initialize(piston3, piston4, anchor1);
			m_world->CreateJoint(&jd1);

			//PISTON5
		  pistonShape.SetAsBox(3.1f, 3.9f);
			pistonbd.position.Set(26.7f, 30.0f);
			pistonFixt.filter.groupIndex = -2;
			piston5 = m_world->CreateBody(&pistonbd);
			piston5->CreateFixture(&pistonFixt);

			//WELDJOINT BETWEEN PISTON3 AND PISTON5
			b2WeldJointDef jd2;
			b2Vec2 anchor2(26.7f, 30.0f);
			jd2.Initialize(piston3, piston5, anchor2);
			m_world->CreateJoint(&jd2);

			//WHEEL3
			wheelbd.position.Set(130,10.5f);
			wheel3 = m_world->CreateBody(&wheelbd);
			wheel3->CreateFixture(&wheelFixt);

			ptbd.position.Set(130,10.5f);
			pt3 = m_world->CreateBody(&ptbd);
			b2RevoluteJointDef rjd3;
			b2Vec2 anchor5(130, 10.5f);
			rjd3.Initialize(pt3, wheel3, anchor5);
			m_world->CreateJoint(&rjd3);

			//SHAFT1
			//shaftbd.position.Set(84.5f, 10.5f);
			b2Vec2 shaft1Vert[4];
			shaft1Vert[0].Set(52,9);
			shaft1Vert[1].Set(52,12);
			shaft1Vert[2].Set(117,11);
			shaft1Vert[3].Set(117, 8);
      shaftShape.Set(shaft1Vert, 4);
			//shaftShape.SetAsBox(32.5f, 1.5f);
			shaft1 = m_world->CreateBody(&shaftbd);
			shaft1->CreateFixture(&shaftFixt);

			b2RevoluteJointDef rjd1;
			b2Vec2 anchor3(52.5f, 10.5f);
			rjd1.Initialize(piston1, shaft1, anchor3);
			m_world->CreateJoint(&rjd1);

			b2RevoluteJointDef rjd2;
			b2Vec2 anchor4(118.5f, 9.5f);
			rjd2.Initialize(shaft1, wheel3, anchor4);
			m_world->CreateJoint(&rjd2);
		
			//SHAFT2
			shaftbd.position.Set(0, 0);
			b2Vec2 shaft2Vert[4];
			shaft2Vert[0].Set(45,29);
			shaft2Vert[1].Set(47,31);
			shaft2Vert[2].Set(130,15);
			shaft2Vert[3].Set(128, 13);
      shaftShape.Set(shaft2Vert, 4);
      shaft2 = m_world->CreateBody(&shaftbd);
      shaft2->CreateFixture(&shaftFixt);
			
			b2RevoluteJointDef rjd4;
			b2Vec2 anchor6(46.5f, 30.0f);
			rjd4.Initialize(piston3, shaft2, anchor6);
			m_world->CreateJoint(&rjd4);

			b2RevoluteJointDef rjd6;
			b2Vec2 anchor7(129.0f, 14.5f);
			rjd6.Initialize(shaft2, wheel3, anchor7);
			m_world->CreateJoint(&rjd6);

			//WHEEL1
			wheelbd.position.Set(70,10.5f);
			wheelFixt.density = 0.01f;
			wheel1= m_world->CreateBody(&wheelbd);
			wheel1->CreateFixture(&wheelFixt);

			ptbd.position.Set(70,10.5f);
			pt1 = m_world->CreateBody(&ptbd);
			b2RevoluteJointDef rjd8;
			b2Vec2 anchor8(70, 10.5f);
			rjd8.Initialize(pt1, wheel1, anchor8);
			m_world->CreateJoint(&rjd8);

			//WHEEL2
			wheelbd.position.Set(100,10.5f);
			wheelFixt.density = 20.0f;
			wheel2 = m_world->CreateBody(&wheelbd);
			wheel2->CreateFixture(&wheelFixt);

			ptbd.position.Set(100,10.5f);
			pt2 = m_world->CreateBody(&ptbd);
			b2RevoluteJointDef rjd7;
			b2Vec2 anchor9(100, 10.5f);
			rjd7.Initialize(pt2, wheel2, anchor9);
			m_world->CreateJoint(&rjd7);

			//SHAFT3 : THE SHAFT JOINING THE THREE WHEELS
			shaftbd.position.Set(100, 2.5f);
			shaftShape.SetAsBox(32.5f, 1.5f);
			shaftFixt.density = 1;
			shaftFixt.filter.groupIndex = -1;
			shaft3 = m_world->CreateBody(&shaftbd);
			shaft3->CreateFixture(&shaftFixt);
			
			b2RevoluteJointDef rjd9;
			b2Vec2 anchor10(70, 2.5f);
			rjd9.Initialize(shaft3, wheel1, anchor10);
			m_world->CreateJoint(&rjd9);
			
			b2RevoluteJointDef rjd10;
			b2Vec2 anchor11(100, 2.5f);
			rjd10.Initialize(shaft3, wheel2, anchor11);
			m_world->CreateJoint(&rjd10);
		
			b2RevoluteJointDef rjd11;
			b2Vec2 anchor12(130, 2.5f);
			rjd11.Initialize(shaft3, wheel3, anchor12);
			m_world->CreateJoint(&rjd11);
			
		}


		
		
		{
	
      b2CircleShape circle;
      circle.m_radius = 0.2f;
	
      b2FixtureDef ballfd;
      ballfd.shape = &circle;
      ballfd.density = 10.0f;
      ballfd.friction = 0.0f;
      ballfd.restitution = 0.95f;
			//ballfd.filter.groupIndex = -1;
			ballfd.filter.categoryBits = 0x0002;
			ballfd.filter.maskBits = 0xFFFF | ~0x0001;

			for (int i = 0; i < n; i++) {
				b2BodyDef ballbd;
				ballbd.type = b2_dynamicBody;
				ballbd.position.Set(rand()%12+15, rand()%5+34);
				spherebody[i] = m_world->CreateBody(&ballbd);
				spherebody[i]->CreateFixture(&ballfd);
				spherebody[i]->SetLinearVelocity( b2Vec2(rand()%200-140,-rand()%200));
			}

			
			}
		
  }

  sim_t *sim = new sim_t("Dominos", dominos_t::create);
	void dominos_t::step(settings_t* settings){
		base_sim_t::step(settings);
		
		for(int i = 0; i < n; i++){
			b2Vec2 pos = spherebody[i]->GetPosition();
			b2Vec2 vel = spherebody[i]->GetLinearVelocity();
			if(pos.y > 44 || pos.y < 0 || pos.x < 0 || pos.x > 38){
				spherebody[i]->SetTransform(b2Vec2(rand()%12+15, rand()%5+34), 0);
				spherebody[i]->SetLinearVelocity( b2Vec2(rand()%1500-750,-rand()%3000));
			}
			else if(pos.x > 37){
				spherebody[i]->SetLinearVelocity(b2Vec2(-vel.x, vel.y));
			}
			else if(pos.x < 26 && pos.x>15 && pos.y > 36 and vel.y > -50)
				spherebody[i]->SetLinearVelocity(b2Vec2(rand()%100-50, vel.y-40));
		}
		
		
	}

	
}

