def main():
    infile=open("castle.png","rb");
    buffersize=50000;
    outfile=open("castlecopy.txt","wb");
    buffer=infile.read(buffersize);
    while(len(buffer)):
        outfile.write(buffer);
        print(len(buffer));
        print();
        buffer=infile.read(buffersize);
    print();
    print("done");
if __name__=="__main__":main()
