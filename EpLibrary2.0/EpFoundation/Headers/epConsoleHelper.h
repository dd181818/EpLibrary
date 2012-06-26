/*! 
@file epConsoleHelper.h
@author Woong Gyu La a.k.a Chris. <juhgiyo@gmail.com>
		<http://github.com/juhgiyo/eplibrary>
@date October 01, 2011
@brief Console Processing Function Class Interface
@version 2.0

@section LICENSE

Copyright (C) 2012  Woong Gyu La <juhgiyo@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

@section DESCRIPTION

An Interface for the Console Processing Operation.

*/
#ifndef __EP_CONSOLE_HELPER_H__
#define __EP_CONSOLE_HELPER_H__
#include "epFoundationLib.h"
#include "epSystem.h"

namespace epl
{
	/// Console Helper ExecuteConsoleCommand WaitTimeStruct
	typedef struct EP_FOUNDATION _waitTimeStruct{
		/// Sleep time for calling thread for each waiting iteration
		unsigned long sleepTimeMilliSec;
		/// Wait time for each iteration
		unsigned long waitTimeMilliSec;

		_waitTimeStruct() { sleepTimeMilliSec=100; waitTimeMilliSec=10;}
		/// default wait time struct
		static _waitTimeStruct wtsDefault; 
	}WaitTimeStruct;

	/*! 
	@class ConsoleHelper epConsoleHelper.h
	@brief This is a class for Console Processing Class

	Implements the Console Processing Functions.
	*/
	class EP_FOUNDATION ConsoleHelper
	{
	public:
		/*!
		Execute the given command to the console and return the result

		** waitStruct is ignored when isWaitForTerminate is false.
		@param[in] command the command to execute
		@param[in] isWaitForTerminate flag for waiting for process to terminate or not
		@param[in] priority the priority of the process executing
		@param[in] waitStruct the wait time and sleep time for current thread if waiting for termination.
		@return the result of the console command
		*/
		static EpTString ExecuteConsoleCommand(const TCHAR * command, bool isWaitForTerminate=true, int priority=CONSOLE_PRIORITY_NORMAL,WaitTimeStruct waitStruct=WaitTimeStruct::wtsDefault);

		/*!
		Execute the given executable file
		@param[in] execFilePath the program file path to execute
		*/
		static void ExecuteProgram(const TCHAR *execFilePath);
	};
}


#endif //__EP_CONSOLE_HELPER_H__