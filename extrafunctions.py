# this is a module for all etra functions which are not classbased
import musicmember as mm
import datetime
import pickle as pk


def input_multline(str="input"):
    """function for reading in multiple lines and safe them as such.
    """
# mutiplelineprint commands are stuipid in python
    print("Enter your", str, ".\nWhen you are finished press Ctrl-D or Ctrl-Z \
(windows) to end your", str, ".")
    contents = []
    while True:
        try:
            line = input()
        except EOFError:
            break
        contents.append(line)
    return line


def print_commands():
    """function to print out all possible commands in the shell to the user.
    """
    print("type: \"new list\" to start a new list.")
    print("\"creat list\" to start a new list works too.")
    print("type: \"genre\" to search for a specific genre.")
    print("type: \"band\" to search for a band.")
    print("type: \"song\" to search for a specific song.")
    print("type: \"album\" to search for a specific album.")


def new_list():
    """function to initialize a new music list.
    maybe needs to be splitted in to seperate functions
    """

    # start of a new musiclist with bandname input
    bandname = input("Please enter the bandname: ")

    # followed by one or more genre(s)
    new_genre = input("\nNow enter ONE genre of the band: ")
    genres = [new_genre]
    test = input("Do you want to more genres? ")
    if test == "yes" or test == "Yes":
        number_new_genres = input("How many more genres do you want do add?\n")
        if number_new_genres > 0:
            for i in (0, number_new_genres):
                new_genre = input("Enter one of the new genres:\n")
                genres.append(new_genre)

    # now coming to the tricky part with adding the bandinfo
    # might need to change that cool trick, since it might make saving and
    # loading impossibly hart to programm... we'll see
    test = input_multline("bandinfo")
    new_bandinfo = input

    # Start of new songlist, first starting with ONE song, asks to be expanded
    # after first song.
    new_songname = input("Now it's time to add a song list. Starting with ONE\
song title: ")

    # Songinfo
    test = input_multline("songinfo")
    new_songinfo = test

    # adding the info in which album the song was published
    new_album = input("Time to add on which album this song was released: ")

    # time for the important stuff, the ducking links:
    new_spotifylink = input("It's finally time to enter the links. Start with \
Spotify: ")
    new_youtubelink = input("Followed by the YouTube-URL: ")

    # setting if the song has prio or not.
    new_prio = input("has this song a high priority for you (yes/no)?: ")
    if (new_prio == "yes" or new_prio == "Yes" or new_prio == "YES" or
            new_prio == "y"):
        new_prio_bool = True
    else:
        new_prio_bool = False

    # actual initializing of the first song in this song list coressponding
    # to the current band.
    addstatus = datetime.datetime.now()
    songlist = []
    songlist[0] = mm.song(new_songname, new_songinfo, new_album,
                          new_spotifylink, new_youtubelink, new_prio_bool,
                          addstatus)

    test = input("Do you want to add more songs to the song list (yes/no)?")
    if(test == "yes" or test == "Yes" or test == "YES" or test == "y"):
            number_new_songs = input("How many songs would you like to add?")

            # adding multiple new songs to the song list like before
            for i in (0, number_new_songs):
                new_songname = input("Time to add a new song to the list. \
Songtitle: ")
                print("Now Enter the songinfo.\n")
                test = input_multline("songinfo")
                new_songinfo = test

            # adding the info in which album the song was published
            new_album = input("Time to add on which album this song was \
released: ")

            # time for the important stuff, the ducking links:
            new_spotifylink = input("It's finally time to enter the links. Start with \
            Spotify: ")
            new_youtubelink = input("Followed by the YouTube-URL: ")

            # setting if the song has prio or not.
            new_prio = input("has this song a high priority for you (yes/no)?")
            if (new_prio == "yes" or new_prio == "Yes" or new_prio == "YES" or
                    new_prio == "y"):
                new_prio_bool = True
            else:
                new_prio_bool = False

                # appending the i-th new song to the song list
                songlist.append(mm.song(new_songname, new_songinfo,
                                new_album, new_spotifylink, new_youtubelink,
                                new_prio_bool))

    print("So this was all to start a new music list. Done for now")
    x = mm.Musicmember(bandname, genres, new_bandinfo, songlist)
    newlist = [x]

    return newlist


def safe(list, file_name="new list"):
    """function to safe the current list in a pickle.
    """
    # open the file for writing
    fileObject = open(file_name, 'wb')

    # this writes the object (music)list to the file named file_name
    pk.dump(list, fileObject)

    # close the fileObject
    fileObject.close()


def load(file_name="new list"):
    """function to load a pickled list.
    """
    # open the file for reading
    fileObject = open(file_name, 'r')

    # load the object from the file into var list
    list = pk.load(fileObject)
    return list
    fileObject.close()
