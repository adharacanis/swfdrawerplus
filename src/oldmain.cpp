//
//  main.cpp
//  WIthTheBoost
//
//  Created by Konstantin Klementiev on 1/23/19.
//  Copyright © 2019 Konstantin Klementiev. All rights reserved.
//

#ifndef WITHTHEBOOST_OLDMAIN_H
#define WITHTHEBOOST_OLDMAIN_H

#include <iostream>

using namespace std;

int oldmain(int argc, const char * argv[]) {
    // insert code here...
    /*fstream file("bikerUncompress.ani", ios_base::in | ios_base::binary);
    
    file.seekg (0, file.end);
    cout << "file stream size: " << file.tellg() << endl;
    long size = file.tellg();
    file.seekg (0, file.beg);

    Bytes* in = new Bytes(size);
    Bytes* out = new Bytes(size);

    unsigned char* iin = in->getData();

    file.read((char*)iin, size);
    file.clear();
    file.seekg (0, file.beg);
    file.close();

    cout << iin << endl;
    //cout << iin[1] << endl;
    //cout << iin[2] << endl;
    cout << iin[0] << endl;

    in->get(0);

    //unflate(in, out);

    int padding = in->get(0);
    int atlasSize = in->getInt32(1);
    int w = in->getInt16(5);
    int h = in->getInt16(7);

    cout << w << ", " << h << endl;



    */

    return 0;
}

/*
    int index = 9;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {

            uint pixel = in->getInt32(index);

            if(pixel > 0)
                rlutil::setBackgroundColor(1);
            else if(pixel == -1)
                rlutil::setBackgroundColor(0);
            else if(pixel < 0)
                rlutil::setBackgroundColor(2);
            else
                rlutil::resetColor();

            int color = floor(pixel / (255*255*255) * 16);

            rlutil::setBackgroundColor(color);

            cout << " ";

            index += 4;
        }
        cout << endl;
    }*/

#endif //WITHTHEBOOST_BYTES_H
