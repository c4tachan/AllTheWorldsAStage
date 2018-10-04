#include <Windows.h>

#include <iostream>
#include <vector>
#include <algorithm>


class Stage
{
public:
	Stage() {};
	~Stage() {};
	
	
};

class Artillery
{
public:
    Artillery()
    {
        m_mouth.push_back("good");
        m_mouth.push_back("bad");
        m_mouth.push_back("bubble");
        m_mouth.push_back("heroic");
    }

    ~Artillery() {}

    typedef std::string reputation;
    reputation Mouth(const reputation& desired) 
    {
        return *find_if(m_mouth.begin(), m_mouth.end(), [&desired](reputation r) 
                {
                    return 0 == strcmp(desired.c_str(), r.c_str());
                } );
    }

private:

    std::vector<reputation> m_mouth;
};


class Infant;

class Nurse
{
public:
	Nurse() {}
	~Nurse() {}
	
	void arms(Infant const*const infnt);
};

//His acts being seven ages.
class Age
{
public:
    Age() {}
    ~Age() {}
	
    virtual void PlayPart() = 0;
};


class Infant : public Age
{
public:
	Infant() {}

    Infant(bool teeth, bool eyes, bool taste, bool anything)
        : m_nurse() 
        , m_bHasTeeth(teeth)
        , m_bHasEyes(eyes)
        , m_bHasTaste(taste)
        , m_bHasAnything(anything)
    {    }


	~Infant() {}
	
	void mewl() const;
	void puke() const;

	virtual void PlayPart();
	
private:
	Nurse m_nurse;

    bool m_bHasTeeth;
    bool m_bHasEyes;
    bool m_bHasTaste;
    bool m_bHasAnything;
};


class SchoolBoy : public Age
{
public:
	SchoolBoy() { m_satchel.hasWith = true; m_face.shine = true; m_bWilling = false; }
	~SchoolBoy() {}
	
	virtual void PlayPart();
	
private:
	struct bag
	{
		bool hasWith;
	};
	
    struct countenance
    {
        bool shine;
    };


	bag m_satchel;
    countenance m_face;
    bool m_bWilling;

	void whine();

	bool HasSatchel() { return m_satchel.hasWith; }
    bool HasShiningFace() { return m_face.shine; }
};

class Lover : public Age
{
public:
	Lover() {}
	~Lover() {}
	
	virtual void PlayPart();
	
private:
	void sigh();
	void makeBallad();
};

class Soldier : public Age
{
public:
    Soldier() 
    {
        m_beard.likePard = true;
        m_vOaths[0] = "I will eat my peas!";
        m_vOaths[1] = "I will obey the earthworms!";
        m_vOaths[2] = "The fourth raindrop shall guide my path!";
        m_vOaths[3] = "I shall defend pi from epsilon!";
        m_vOaths[4] = "My sword shall never strike a butterfly!";
    }
    ~Soldier() {}

    virtual void PlayPart();

private:
    struct facialHair
    {
        bool likePard;
    };

    typedef std::string Oath;

    facialHair m_beard;
    Oath m_vOaths[5];
};

class Justice : public Age
{
public:
    Justice() {}
    ~Justice() {}

    virtual void PlayPart();

private:

};

class Pantaloon : public Age
{
public:
    Pantaloon() {}
    ~Pantaloon() {}

    virtual void PlayPart();


};


class Player
{
public:
	//They have their exits and their entrances,
	Player() {}
	~Player() {}
	

	void time();
	
private:
	std::vector<Age*> m_parts;

};