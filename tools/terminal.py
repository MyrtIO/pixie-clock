"""Script to connect to a clock in terminal mode to enter commands and display output"""
from serial import Serial
from time import sleep

HEADER_FIRST = 0xFE
HEADER_SECOND = 0xEF
TAIL = 0xAF

class ANSIColor:
  DIM = "\033[2m"
  RESET = "\033[0m"
  RED = "\033[0;31m"

def format_message(values: list[int], colored = True) -> str:
  strings = []
  last_index = len(values) - 1
  for i, value in enumerate(values):
    if colored and (i <= 2 or i == last_index):
      strings.append(f"{ANSIColor.DIM}{value}{ANSIColor.RESET}")
    else:
      strings.append(str(value))
  return ' '.join(strings)

def is_correct(values: list[int]) -> str:
  count = len(values)
  return values[0] == HEADER_FIRST and \
    values[1] == HEADER_SECOND and \
    values[2] == count - 4 and \
    values[count-1] == TAIL

class MyrtIOAPI:
  _stream: Serial

  def __init__(self, port: str, rate: int):
    self._stream = Serial(port, rate, timeout=1, dsrdtr=True)

  def connect(self):
    if self._stream.is_open:
      self._stream.close()
    self._stream.open()

  def reset(self):
    self._stream.dtr = 0
    sleep(0.2)
    self._stream.dtr = 1

  def send(self, payload: list[int]) -> list[int]:
    data = [HEADER_FIRST, HEADER_SECOND, len(payload), *payload, TAIL]
    message = bytes(data)
    print(f"-> Send: {format_message(data)}")
    self._stream.write(message)
    sleep(0.1)
    output = list(self._stream.read_all())
    is_output_correct = is_correct(output)
    if not is_output_correct:
      print(f"{ANSIColor.RED}Incorrect output format{ANSIColor.RESET}")
    print(f"<- Read: {format_message(output, is_output_correct)}")
    return output

api = MyrtIOAPI('/dev/cu.wchusbserial14320', 9600)
while True:
  value = input("Command: ")
  # args = value.split(" ")
  # sub_args =
  numbers = list(map(int, value.split(" ")))
  api.send(numbers)


