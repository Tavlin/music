# this is a module for all etra functions which are not classbased


def input_multline(str="input"):
    print("Enter your", str, ".\nWhen you are finished press Ctrl-D or Ctrl-Z \
(windows) to end your", str, ".")
# mutiplelineprint commands are stuipid in python
    contents = []
    while True:
        try:
            line = input()
        except EOFError:
            break
        contents.append(line)
    return line
