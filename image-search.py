
import os
import shutil

scannedDir = input("Enter the top directory to scan for images: ")
copyDir = input("Enter the directory to copy image files to: " )

wantedFileTypes = ["PNG", "jpg", "png"]


for root, dirs, files in os.walk(scannedDir, topdown=False):
   for name in files:
      splitFile = name.split('.')
      print(os.path.join(root, name))
      try:
          fileType = splitFile[1]

          print(fileType)
          i=0
          max = len(wantedFileTypes)
          for i in range(max):
              if fileType == wantedFileTypes[i]:
                  print("File match found, copying...")
                  shutil.copy(os.path.join(root, name), copyDir)
      except IndexError:
          print("File type not found, ignoring")
      except OSError:
          print("Permissions issue, ignoring")
   #for name in dirs:
      #print(os.path.join(root, name))
