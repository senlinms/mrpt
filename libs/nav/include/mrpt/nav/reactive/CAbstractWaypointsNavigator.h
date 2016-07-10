/* +---------------------------------------------------------------------------+
   |                     Mobile Robot Programming Toolkit (MRPT)               |
   |                          http://www.mrpt.org/                             |
   |                                                                           |
   | Copyright (c) 2005-2016, Individual contributors, see AUTHORS file        |
   | See: http://www.mrpt.org/Authors - All rights reserved.                   |
   | Released under BSD License. See details in http://www.mrpt.org/License    |
   +---------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/nav/reactive/CAbstractNavigator.h>
#include <mrpt/nav/reactive/TWaypoint.h>

namespace mrpt
{
  namespace nav
  {
	/** Base virtual class for reactive/planned navigation system capable of following a list of waypoints. See derived classes.
	 * \sa base class CAbstractNavigator, CAbstractWaypointsNavigator::navigateWaypoints(), and derived classes.
	 *  \ingroup nav_reactive
	 */
	class NAV_IMPEXP CAbstractWaypointsNavigator : public  mrpt::nav::CAbstractNavigator
	{
	public:
		CAbstractWaypointsNavigator( CRobot2NavInterface &robot_interface_impl );  //!< ctor
		virtual ~CAbstractWaypointsNavigator(); //!< dtor

		/** \name Waypoint navigation control API
		  * @{ */

		/** Waypoint navigation request.
		  * \sa CAbstractNavigator::navigate() for single waypoint navigation requests.
		  */
		void navigateWaypoints( const TWaypointSequence &params );

		/** Get a copy of the control structure which describes the progress status of the waypoint navigation. */
		void getWaypointNavStatus(TWaypointStatusSequence & out_nav_status) const;
		/** @}*/

	protected:
		TWaypointStatusSequence  m_waypoint_nav_status; //!< The latest waypoints navigation command and the up-to-date control status.

	};
  }
}
