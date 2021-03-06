/*
 *BSD 3-Clause License
 *
 *Copyright (c) 2017, Pranav Inani
 *All rights reserved.
 *
 *Redistribution and use in source and binary forms, with or without
 *modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/**
 *  @file Turtle.h
 *
 *  @brief Header File for turtle Class
 *
 *  @author Pranav Inani
 *  @copyright 2017
 */
#include "terrapinavigator/Navigator.h"
#include <terrapinavigator/pictureService.h>
#include "TerpCam.h"

#ifndef TERRAPINAVIGATOR_INCLUDE_TERRAPINAVIGATOR_TURTLE_H_
#define TERRAPINAVIGATOR_INCLUDE_TERRAPINAVIGATOR_TURTLE_H_
/**
 * @brief Turtle class
 *
 * Initializes various subscriber, publishers and timers
 * Has a method to publish twist messges.
 *
 */
class Turtle {
 public:
  /**
   * @brief Constructor for Turtle Class
   */
  Turtle();
  /**
   *
   * @brief Publishes twist messages
   *
   * @return true if successful
   *
   */
  bool explore();
  /**
   * @brief Destructor for Turtle Class
   */
  ~Turtle();
 private:
  ros::NodeHandle n;
  /**
   * @brief Creates TerpCam Object
   */
  TerpCam cam = TerpCam();
  /**
   * @brief Creates Navigator Object
   */
  Navigator navigator = Navigator();
  /**
   * @brief registers subscriber for image pointers
   */
  ros::Subscriber cameraSub;
  /**
   * @brief registers server for camera service
   */
  ros::ServiceServer takeImageServer;
  /**
   * @brief registers subcriber for topic /scan
   */
  ros::Subscriber subLaserScan;
  /**
   * @brief registers timer for rotating the turtleBot
   */
  ros::Timer Rotatetimer;
  /**
   * @brief registers timer for camera service
   */
  ros::Timer camTimer;
  /**
   * @brief registers publisher for action(twist) messages
   */
  ros::Publisher actionPub;

};

#endif /* TERRAPINAVIGATOR_INCLUDE_TERRAPINAVIGATOR_TURTLE_H_ */
