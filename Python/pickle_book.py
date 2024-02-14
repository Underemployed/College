import pickle
def add_record():
  with open('book.dat','ab') as file:
    bno = int ((input("no:")))
    bname = input("name:")
    author = input( "author:")
    price = float(input('Enter price:'))
    record = [bno,bname,author,price]
    pickle.dump(record,file)

def display_records():
  with open('book.dat','rb') as file:
    while True:
      try:
        record = pickle.load(file)
        print(record)
      except EOFError:
        break

def books_by_author(author):
  with open('book.dat','rb') as file:
    while True:
      try:
        record=pickle.load(file)
        if record[2]==author:
          print(record)
      except EOFError:
        break

def copy_data():
  count=0
  with open('book.dat','rb') as file:
    with open('costly_book.dat','ab') as new_file:
      while True:
        try:
          record = pickle.load(file)
          if record[3] > 500:
            pickle.dump(record,new_file)
            count += 1
        except EOFError:
          break
  return count

def delete_record(bno):
  found = False
  temp_file = 'temp.dat'
  with open('book.dat','rb+') as file:
    with open(temp_file,'ab') as temp:
      while True:
        try:
            record = pickle.load(file)
            if record[0] == bno:
                found = True
            else:
                pickle.dump(record, temp)
        except EOFError:
            break
      if found:
        import os
        os.remove('book.dat')
        os.rename(temp_file, 'book.dat')
      else:
        print('Record not found!')
def update_record(bno):
  found = False
  temp_file = 'temp.dat'
  with open('book.dat', 'rb') as file, open(temp_file, 'ab') as temp:
    while True:
      try:
          record = pickle.load(file)
          if record[0] == bno:
              found = True
              Book_Name = input('Enter updated Book Name: ')
              Author = input('Enter updated Author: ')
              Price = float(input('Enter updated Price: '))
              updated_record = [bno, Book_Name, Author, Price]
              pickle.dump(updated_record, temp)
          else:
              pickle.dump(record, temp)
      except EOFError:
          break
  if found:
    import os
    os.remove('book.dat')
    os.rename(temp_file, 'book.dat')
  else:
    print('Record not found!')