# Fibonacci numbers module
import extrafunctions as ef
status = 1


def main():
    print("Welcome to the musiclist program!")
    while status == 1:

        print("Please choose what you want to do:")
        print("Type help for help, or any other command you wish to execute.")
        input = ef.input_multline("command")
        if input == "exit" or input == "Exit":
            break

        elif input == "help" or input == "Help":
            pass  # print_commands()

        elif input == "creat list" or input == "new list":
            pass  # new_list()


if __name__ == "__main__":
    # execute only if run as a script
    main()
