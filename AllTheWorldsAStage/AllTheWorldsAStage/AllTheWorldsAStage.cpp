#include "AllTheWorldsAStage.h"

using namespace std;

/******************************************************
 *                                                    *
 *                                                    *
 *                                                    *
 *	Begin the functional code                         *
 *                                                    *
 *                                                    *
 *                                                    * 
 ******************************************************/

//////////////////////////////////////////////////////////////
// Begin Infant
//////////////////////////////////////////////////////////////
void Nurse::arms(Infant const*const infnt)
{
	//Mewling and puking in the nurse's arms.
	infnt->mewl();
	infnt->puke();
}

void Infant::mewl() const
{
    MessageBox(NULL, "goo goo gah gah!", "Player (as baby):", MB_OK);
}

void Infant::puke() const
{
    MessageBox(NULL, "Eww, gross he puked on me!", "Nurse (holding player):", MB_OK);
}

 void Infant::PlayPart()
 {
	m_nurse.arms(this);
 }
 
 //////////////////////////////////////////////////////////////
 // End Infant
 // Begin School Boy
 //////////////////////////////////////////////////////////////

 void SchoolBoy::whine()
 {
     MessageBox(NULL, "I don't wanna go to school this sucks!", "Player (as school boy):", MB_OK);
 }


 void SchoolBoy::PlayPart()
 {
	whine();
	// with his satchel
	if(  (HasSatchel())
	//And shining morning face,
	  && (HasShiningFace())
	  )
	{
		//creeping like snail
		Sleep(1000);
		//Unwillingly to school.
		if(!m_bWilling)
        {
            goto School;
        }
	}
School:
    return;
 }
 
//////////////////////////////////////////////////////////////
// End School Boy
// Begin Lover
//////////////////////////////////////////////////////////////

 void Lover:: sigh()
 {
     MessageBox(NULL, "Ahhh!", "Player (as young man passionately in love):", MB_OK);
 }

 void Lover::makeBallad()
 {
     MessageBox(NULL, "Your eyebrow tears my heart strings/ Were that I could be it/ I'd never be without you for anything!", "Player (as young man in love) [singing] :", MB_OK);
 }


 void Lover::PlayPart()
 {
	//Sighing like furnace,
	sigh();
	
	//with a woeful ballad
	//Made to his mistress' eyebrow.
	makeBallad();
 }
 

//////////////////////////////////////////////////////////////
// End Lover
// Begin Soldier
//////////////////////////////////////////////////////////////
 void Soldier::PlayPart()
 {
     bool oathsFull = true;

     for(auto oath : m_vOaths)
     {
         if(oath.empty())
         {
            oathsFull = false;
         }
     }

     //Full of strange oaths, and bearded like the pard,
     if(oathsFull && m_beard.likePard)
     {
        //Jealous in honour, sudden, and quick in quarrel,

        //Seeking the bubble reputation
        //Even in the cannon's mouth. 
        Artillery cannon;
        MessageBox(NULL, cannon.Mouth("bubble").c_str(), "Player (as soldier finds)", MB_OK);
     }

 }

//////////////////////////////////////////////////////////////
// End Soldier
// Begin Justice
//////////////////////////////////////////////////////////////

void Justice::PlayPart()
{
    //In fair round belly, with a good capon lined,
    //With eyes severe, and beard of formal cut,
    //Full of wise saws, and modern instances,
    //And so he plays his part. 
}

//////////////////////////////////////////////////////////////
// End Justice
// Begin Pantaloon
//////////////////////////////////////////////////////////////

void Pantaloon::PlayPart()
{

}


void Player::time()
{
    //And one man in his time plays many parts,

	//At first the infant,
	m_parts.push_back(new Infant());
	
	//Then, the whining school-boy
	m_parts.push_back(new SchoolBoy());
	
	//And then the lover,
	m_parts.push_back(new Lover());
	
	//Then, a soldier,
	m_parts.push_back(new Soldier());
	
	//And then, the justice,
    m_parts.push_back(new Justice());

    //The sixth age shifts
    //Into the lean and slippered pantaloon,
    m_parts.push_back(new Pantaloon());

    //Turning again toward childish treble, pipes
    //And whistles in his sound. Last scene of all,
    //That ends this strange eventful history,
    //Is second childishness and mere oblivion,
    m_parts.push_back(new Infant(false, false, false, false));

    for(auto part : m_parts)
    {
        part->PlayPart();
    }

}


int main()
{
	//All the world's a stage,
	Stage world;
	
	//And all the men and women merely players;
	Player men;
	Player women;
	
	men.time();
	
    return 0;
}






//With spectacles on nose and pouch on side,
//His youthful hose, well saved, a world too wide
//For his shrunk shank, and his big manly voice,

//Sans teeth, sans eyes, sans taste, sans everything.