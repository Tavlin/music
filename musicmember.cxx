#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/*******************************************************************************
struct for a single song, including the songname, the info about the song,
the URL to open the song in spotify and the URL to open it on YouTube.
*******************************************************************************/
struct song{
  string songname;
  string songinfo;
  string album;
  string spotifylink;
  string youtubelink;
  bool prio;

};

/*******************************************************************************
class which contains one band, all the genres, all their important songs and
the band info
*******************************************************************************/
class Musicmember
{
    string bandname;
    vector<string> genres;
    string bandinfo;
    vector<song> songlist;

  public:
    // normal constructor
    Musicmember(string, vector<string>, string, vector<song>);

    // function to add a new song to the songlist
    void AddSong(song added_song)
    {
      Musicmember::songlist.push_back(added_song);
    }

    // function to add a Genre to the list of genres
    void AddGenre(string added_genre){
      Musicmember::genres.push_back(added_genre);
    }

    // function to add additional info about the band
    void AddBandInfo(string added_bandinfo){
      Musicmember::bandinfo.append("\n");
      Musicmember::bandinfo.append(added_bandinfo);
    }

    // function to change the name of the band if you missspelled it
    void ChangeBandname(string new_bandname){
      Musicmember::bandname = new_bandname;
    }

    // function to change the info of the band
    void ChangeBandinfo(string new_bandinfo){
      Musicmember::bandinfo = new_bandinfo;
    }



};
// normal constructor
Musicmember::Musicmember(string a, vector<string> b, string c, vector<song> d){
  bandname = a;
  genres = b;
  bandinfo = c;
  songlist = d;
}

vector<Musicmember> list;


int main(int argc, char* argv[]){

  return 0;
}
