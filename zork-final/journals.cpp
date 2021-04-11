#include "journals.h"
#include "ui_journals.h"
#include <QMessageBox>

template <class T>
          class journalNo{
          T number;
          public:
          journalNo(T a){
            if(a == 1){
               number = a;
            }else if(a == 3){
                number = a;
            }else if(a == 6){
                number = a;
            }else{
                number = a;
            }
          }
          T get();
          };

template <class T>
          T journalNo<T>::get(){
            return number;
          }

Journals::Journals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Journals)
{
    ui->setupUi(this);

    QString j1 = "";
    QString j2 = "";
    QString j3 = "";
    QString j4 = "";
          journalNo <int> jour1(1);
          j1 = QString::number(jour1.get());
          journalNo <double> jour2(3);
          j2 = QString::number(jour2.get());
          journalNo <int> jour3(6);
          j3 = QString::number(jour3.get());
          journalNo <double> jour4(9);
          j4 = QString::number(jour4.get());

          struct Union{
            union{
                int a;
                double b;
                int c;
                double d;
            };
          };

          int count = 0;
          Union u;
          u.a = jour1.get();
          count++;
          u.b = jour2.get();
          count++;
          u.c = jour3.get();
          count++;
          u.d = jour4.get();
          count++;

          int diff;
          if(u.d > count){
              diff = u.d - count;
          }else{
              diff = count;
          }
    QMessageBox msgBox;
    QString journalText =   "you found " +  QString::number(u.d - diff) + " journal entries. the others must have been lost. \n"
                            "Journal entry " + j1 + ": New Kid on the Block \n"
                            "Alright! I'm Beatudice Vorcheth Nimghith II, but Bee is fine. They tell me I have to keep audio logs now, as part of my employment contract, so here I am. "
                            "Not a problem really. I used to do this at school all the time with Jana and Rees. Well, I guess I should introduce myself. I'll be the new researcher at this facility.  "
                            "Don't know much about what I'll be researching yet, but you gotta take what you can get. Work's hard to come by these days, espically when you have thousands of credits "
                            "worth of student loans to pay off. Anyway, I think it's got something to do with gravity technology, oh well, guess I'll find out. I've only met Reyes so far, the others "
                            "were busy. He seems like a sweet guy. Bit old for my tastes though. A few years ago though... Anyways, he's the one who showed me around. Apparently the head of "
                            "research will be meeting me soon. Hopefully he's nice too. I know my mom told me not to take it, but so far this job is shaping up to be just great! Good people, good "
                            "pay and even some interesting stuff to work on. What more could a girl ask for. I hope Jana and Rees are doing well. Rees was still looking for work last I heard, but  "
                            "I'm sure she'll find some. They don't let us send messages out of the facility, so I won't know until my next shore leave in three months. *Knocking on door*  "
                            "Oh that must be the head of research, I better go!  \n"
                            "\n"
                            "Journal entry " + j2 + ": Suck it Renne \n"
                            "Hey diar- I mean audio log.  Something weird just happened today.  I've been here over a month now and we've made a breakthrough in the design. "
                            "It's looking like we'll be ready to start testing before my shore leave - yaaaaay! But a transport just showed up for the occasional resupply that we get and dropped "
                            "off some 'security droids'.  These aren't your regular security droids, these are biiig.  I've seen them before on holovids, they're B2 friggen battledroids!  Like, you "
                            "know, the ones the separatists use!  Renne would be soo mad.  She studied for five years in advanced robotics and didn't get to see anything more advanced than an R6 "
                            "astromech and here I am standing beside the BEST BATTLEDROID EVER - EEEEEEEEEEEE!  I'm gonna name them.  Bonnie and Clyde... no that won't work, what kind of name is "
                            "Clyde anyway... Bruce and Bruno!  That's it.  I'm going to go tell everyone about Bruce and Bruno! \n"
                            "\n"
                            "Journal entry " + j3 + ": THEY'RE ALL DEAD!!! \n"
                            "Shit, shit, SHIT!  By the force Bee calm down... They're dead, all of them... He killed them, he must have.  OKokokokok.  So Eiy asked everyone to go to the hazardous "
                            "materials locker to help him with transporting some element in the store to be examined in the research bay then when they were in there he... he, sealed the doors and "
                            "gassed the room...  The bastard...  I wasn't there... I was taking a quick nap after researching all day. I'm gonna find tha - *sounds of a shuttle launch*.   *Sighs* "
                            "Well I guess that's it then.  I'll try to survive here for as long as I can, but the rations won't last forever.  I guess I could maybe try to forage in the tundra "
                            "Reyes said he saw a lot of plants there, maybe on lower ground there'll be something to eat.  I'll stay here as long as I can though.  Damn it mom... I should have "
                            "listened... \n"
                            "\n"
                            "Journal entry " + j4 + ": Guess this is it... \n"
                            "I guess this is it diary.  *Coughs*  been fun, huh.  From naïve petty college girl to sole survivor of a mysterious facility that is almost certainly run by the "
                            "separatists.     I tried my plan to disable Bruce and Bruno.  I hit the generator and ran.  The power went *coughs* the power went down alright and just as I thought, "
                            "the droids went to dock.  What I didn't think though, would be that Baktoid would have put in such a strong firewall.  Makes sense now that I think about it *cough*. "
                            "Don't want the Republic hacking your army *pained laughter*.  Anyways when I tried to wipe Bruce he immediately powered on and well, let's just say researcher... doesn't "
                            "win against Super Battledroid *coughing laughter*.   If anyone finds this, All ive managed to find is an explanation of what the device was really for. ive taped it to "
                            "the back of this audio log device. Well, guess I should have listened to you mom.  ""Don't go"", she said, ""it's too good to be true"". You were right mom... you were-   [Log Ended Due to Inactivity]";
    msgBox.setText(journalText);
    msgBox.setInformativeText("Close Journals?");
    msgBox.setStandardButtons(QMessageBox::Close);
    msgBox.setDefaultButton(QMessageBox::Close);
    int ret = msgBox.exec();
}


Journals::~Journals()
{
    delete ui;
}
