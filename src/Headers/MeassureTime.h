/*
 * MeassureTime.h
 *
 *  Created on: 27.10.2016
 *      Author: nlz
 */

#ifndef HEADERS_MEASSURETIME_H_
#define HEADERS_MEASSURETIME_H_

/**
 *
 * Alle für die Zeit Messung im Tmaaplet bauen !
 *
 * EXMAPLE schauen da  noch die zeitmessung in double geschieht.
  	auto start_time = chrono::high_resolution_clock::now();
	int temp;
	for (int i = 0; i < 242000000; i++)
		temp += temp;
	auto end_time = chrono::high_resolution_clock::now();
	cout
			<< chrono::duration_cast<chrono::seconds>(end_time - start_time).count()
			<< ":";
	cout
			<< chrono::duration_cast<chrono::microseconds>(
					end_time - start_time).count() << ":";
	cout << "Hello world!" << endl;

 *
 *
 *
 *
 */



#endif /* HEADERS_MEASSURETIME_H_ */
