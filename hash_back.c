//
// Created by Lakshay Raj on 27-11-2017.
//


#include "data.h"

bool insert_hash(int num) {
    int root = num % HASH_KEY;

    if (hashNodes[root][hashTravelled].data != -1) {
        hashNodes[root][hashTravelled].data = num;
        hashTravelled = 0;

        return true;
    }

    return false;
}

void SetupHashData() {

//    hashPositions[0][0].x = 50;
//    hashPositions[0][0].y = 100;
//
//    hashPositions[1][0].x = 50;
//    hashPositions[1][0].y = 210;
//
//    hashPositions[2][0].x = 50;
//    hashPositions[2][0].y = 320;
//
//    hashPositions[3][0].x = 50;
//    hashPositions[3][0].y = 430;
//
//    hashPositions[4][0].x = 50;
//    hashPositions[4][0].y = 540;

    for (i = 0; i < 50; i++) {
        for (j = 0; j < 50; j++) {
            hashNodes[i][j].data = -1;
            hashPositions[i][j].x = HASH_STARTX + j * (2 * HASH_WIDTH + HASH_SAPERATIONX);
            hashPositions[i][j].y = HASH_STARTY - i * (2 * HASH_HEIGHT + HASH_SAPERATIONY);

            hashNodes[i][j].isEnabled = false;
            hashNodes[i][j].isSelected = false;
            hashNodes[i][j].data = -1;

//            if(rand()%3 == 0){
//                hashNodes[i][j].isEnabled = true;
//                hashNodes[i][j].isSelected = false;
//                hashNodes[i][j].data = rand() % 10;
//            }

            texts[0].description = "We have the first number ";
            texts[1].description = "We have the next number ";
            texts[2].description = "Since the root is empty, we place the number ";
            texts[3].description = "We place the number ";
            texts[4].description = "Moving on...";
            texts[5].description = "Since the root is not empty, we need to traverse";
            texts[6].description = "Moving forward in linked list";
            texts[7].description = "End of list reached !!";
            texts[8].description = "Hash Map is completed";
            texts[9].description = "";
            texts[10].description = "So we create a node";
            texts[11].description = "Now Let's see how the physical looks for this DS";
            texts[12].description = "This is how the physical memory is right now";

        }
    }

    n = 9;
    m = 15;

    int j, counter = 0;
    for (i = 0; i < 25; i++)
        for (j = 0; j < 25; j++) {
//                mapTreeMemoryPositions();
            int x = rand() % n;
            int y = rand() % m;

            if (data[x][y].value == 0) {
                data[x][y].value = 1;
                counter++;
            }

            if (counter == length)
                return;
        }

}
