#include <iostream>
using namespace std;

class RecordPlayer {
   public:
        virtual void play() = 0;
        virtual void pause() = 0;
        virtual void rewind() = 0;

};

class OldPlayer {
   public:
        void gramaphoneStart() {
             cout << "Song started" << endl;
        }

        void gramaphoneStop() {
             cout << "Song stopped" << endl;
        }

        void gramaphoneRewind() {
             cout << "Rewinding song" << endl;
        }
};

// Adapter - Acts as a wrapper on top of old player 
class ModernPlayer : public RecordPlayer {
        OldPlayer *oldplayer = new OldPlayer();

        public:
            void play() {
               oldplayer->gramaphoneStart();
            }
            void pause() {
               oldplayer->gramaphoneStop();
            }
            void rewind() {
               oldplayer->gramaphoneRewind();
            }
};           
               

int main()
{
   ModernPlayer player;

   player.play();
   player.pause();
   player.rewind();
}
