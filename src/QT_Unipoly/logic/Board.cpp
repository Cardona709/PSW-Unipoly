#include "../include/logic/Board.h"
#include "../include/logic/Property.h"
#include "../include/logic/Faculty.h"
#include "../include/logic/Station.h"
#include "../include/logic/Utility.h"
#include "../include/logic/Cards.h"
#include <string>

// Path: src/Faculty.h
using namespace logic;

// function to create the board
void Board::create_board(){
    // create all rent prices
    std::vector<std::vector<int>> rent_price = {{ 2,   10,   30,   90,  160,  250},
                                            { 4,   20,   60,  180,  320,  450},
                                            { 6,   30,   90,  270,  400,  550},
                                            { 6,   30,   90,  270,  400,  550},
                                            { 8,   40,  100,  300,  450,  600},
                                            {10,   50,  150,  450,  625,  750},
                                            {10,   50,  150,  450,  625,  750},
                                            {12,   60,  180,  500,  700,  900},
                                            {14,   70,  200,  550,  750,  950},
                                            {14,   70,  200,  550,  750,  950},
                                            {16,   80,  220,  600,  800, 1000},
                                            {18,   90,  250,  700,  875, 1050},
                                            {18,   90,  250,  700,  875, 1050},
                                            {20,  100,  300,  750,  925, 1100},
                                            {22,  110,  330,  800,  975, 1150},
                                            {22,  110,  330,  800,  975, 1150},
                                            {24,  120,  360,  850, 1025, 1200},
                                            {26,  130,  390,  900, 1100, 1275},
                                            {26,  130,  390,  900, 1100, 1275},
                                            {28,  150,  450, 1000, 1200, 1400},
                                            {35,  175,  500, 1100, 1300, 1500},
                                            {50,  200,  600, 1400, 1700, 2000}
                                            }; 


   //create all faculties
    Faculty* ISEP   = new Faculty("ISEP",   60,  30,  rent_price[0],  BROWN, 50  );
    Faculty* ESE    = new Faculty("ESE",    60,  30,  rent_price[1],  BROWN, 50  );
    Faculty* ESS    = new Faculty("ESS",    100, 50,  rent_price[2],  LIGHTBLUE, 50  );
    Faculty* FCNAUP = new Faculty("FCNAUP", 100, 50,  rent_price[3],  LIGHTBLUE, 50  );
    Faculty* FFUP   = new Faculty("FFUP",   120, 60,  rent_price[4],  LIGHTBLUE, 50  );
    Faculty* IPAM   = new Faculty("IPAM",    140, 70,  rent_price[5],  PINK, 100 );
    Faculty* ISCAP  = new Faculty("ISCAP",  140, 70,  rent_price[6],  PINK, 100 );
    Faculty* ISMAI  = new Faculty("ISMAI",  160, 80,  rent_price[7],  PINK, 100 );
    Faculty* FADEUP = new Faculty("FADEUP", 180, 90,  rent_price[8],  ORANGE, 100 );
    Faculty* FLUP   = new Faculty("FLUP",   180, 90,  rent_price[9],  ORANGE, 100 );
    Faculty* FBAUP  = new Faculty("FBAUP",  200, 100, rent_price[10], ORANGE, 100 );
    Faculty* FDUP   = new Faculty("FDUP",   220, 110, rent_price[11], RED, 150 );
    Faculty* FCUP   = new Faculty("FCUP",   220, 110, rent_price[12], RED, 150 );
    Faculty* FEP    = new Faculty("FEP",    240, 120, rent_price[13], RED, 150 );
    Faculty* FMDUP  = new Faculty("FMDUP",  260, 130, rent_price[14], YELLOW, 150 );
    Faculty* ICBAS  = new Faculty("ICBAS",  260, 130, rent_price[15], YELLOW, 150 );
    Faculty* FPCEUP = new Faculty("FPCEUP", 280, 140, rent_price[16], YELLOW, 150 );
    Faculty* FAUP   = new Faculty("FAUP",   300, 150, rent_price[17], GREEN, 200 );
    Faculty* ESMAE  = new Faculty("ESMAE",  300, 150, rent_price[18], GREEN, 200 );
    Faculty* ESEP   = new Faculty("ESEP",   320, 160, rent_price[19], GREEN, 200 );
    Faculty *FMUP   = new Faculty("FMUP",   350, 175, rent_price[20], DARKBLUE, 200 );
    Faculty *FEUP   = new Faculty("FEUP",   400, 200, rent_price[21], DARKBLUE, 200 );

    //create all stations
    Station* TRINDADE             = new Station("TRINDADE");
    Station* SENHOR_DE_MATOSINHOS = new Station("SENHOR_DE_MATOSINHOS");
    Station* CAMPANHA             = new Station("CAMPANHA");
    Station* POLO_UNIVERSITARIO   = new Station("POLO_UNIVERSITARIO");

    //create all utilities
    Utility* BEER    = new Utility("BEER");
    Utility* CANTINE = new Utility("CANTEEN");

    //create all properties
    positions.push_back(new Property(NULL, GO,              NULL,   NULL,                 NULL,0));//0
    positions.push_back(new Property(NULL, FACULTY,         ISEP,   NULL,                 NULL,1));//1
    positions.push_back(new Property(NULL, COMMUNITY_CHEST, NULL,   NULL,                 NULL,2));//2
    positions.push_back(new Property(NULL, FACULTY,         ESE,    NULL,                 NULL,3));//3
    positions.push_back(new Property(NULL, TAX,             NULL,   NULL,                 NULL,4));//4
    positions.push_back(new Property(NULL, STATION,         NULL,   TRINDADE,             NULL,5));//5
    positions.push_back(new Property(NULL, FACULTY,         ESS,    NULL,                 NULL,6));//6
    positions.push_back(new Property(NULL, CHANCE,            NULL,   NULL,                 NULL,7));//7
    positions.push_back(new Property(NULL, FACULTY,         FCNAUP, NULL,                 NULL,8));//8
    positions.push_back(new Property(NULL, FACULTY,         FFUP,   NULL,                 NULL,9));//9
    positions.push_back(new Property(NULL, JAIL,            NULL,   NULL,                 NULL,10));//10
    positions.push_back(new Property(NULL, FACULTY,         IPAM,   NULL,                 NULL,11));//11
    positions.push_back(new Property(NULL, UTILITY,         NULL,   NULL,                 BEER,12));//12
    positions.push_back(new Property(NULL, FACULTY,         ISCAP,  NULL,                 NULL,13));//13
    positions.push_back(new Property(NULL, FACULTY,         ISMAI,  NULL,                 NULL,14));//14
    positions.push_back(new Property(NULL, STATION,         NULL,   SENHOR_DE_MATOSINHOS, NULL,15));//15
    positions.push_back(new Property(NULL, FACULTY,         FADEUP, NULL,                 NULL,16));//16
    positions.push_back(new Property(NULL, COMMUNITY_CHEST, NULL,   NULL,                 NULL,17));//17
    positions.push_back(new Property(NULL, FACULTY,         FLUP,   NULL,                 NULL,18));//18
    positions.push_back(new Property(NULL, FACULTY,         FBAUP,  NULL,                 NULL,19));//19
    positions.push_back(new Property(NULL, FREE_PARKING,    NULL,   NULL,                 NULL,20));//20
    positions.push_back(new Property(NULL, FACULTY,         FDUP,   NULL,                 NULL,21));//21
    positions.push_back(new Property(NULL, CHANCE,            NULL,   NULL,                 NULL,22));//22
    positions.push_back(new Property(NULL, FACULTY,         FCUP,   NULL,                 NULL,23));//23
    positions.push_back(new Property(NULL, FACULTY,         FEP,    NULL,                 NULL,24));//24
    positions.push_back(new Property(NULL, STATION,         NULL,   CAMPANHA,             NULL,25));//25
    positions.push_back(new Property(NULL, FACULTY,         FMDUP,  NULL,                 NULL,26));//26
    positions.push_back(new Property(NULL, FACULTY,         ICBAS,  NULL,                 NULL,27));//27
    positions.push_back(new Property(NULL, UTILITY,         NULL,   NULL,                 CANTINE,28));//28
    positions.push_back(new Property(NULL, FACULTY,         FPCEUP, NULL,                 NULL,29));//29
    positions.push_back(new Property(NULL, GO_TO_JAIL,      NULL,   NULL,                 NULL,30));//30
    positions.push_back(new Property(NULL, FACULTY,         FAUP,   NULL,                 NULL,31));//31
    positions.push_back(new Property(NULL, FACULTY,         ESMAE,  NULL,                 NULL,32));//32
    positions.push_back(new Property(NULL, COMMUNITY_CHEST, NULL,   NULL,                 NULL,33));//33
    positions.push_back(new Property(NULL, FACULTY,         ESEP,   NULL,                 NULL,34));//34
    positions.push_back(new Property(NULL, STATION,         NULL,   POLO_UNIVERSITARIO,   NULL,45));//35
    positions.push_back(new Property(NULL, CHANCE,            NULL,   NULL,                 NULL,36));//36
    positions.push_back(new Property(NULL, FACULTY,         FMUP,   NULL,                 NULL,37));//37
    positions.push_back(new Property(NULL, TAX,             NULL,   NULL,                 NULL,38));//38
    positions.push_back(new Property(NULL, FACULTY,         FEUP,   NULL,                 NULL,39));//39
    
    // Create all cards
    // Chance Cards
    chance_cards.push_back(new ChanceCard("Advance to Go", 0, "Advance to Go. Collect ECTS 200."));
    chance_cards.push_back(new ChanceCard("Advance to FEP", 1, "Advance to FEP. If you pass Go, collect ECTS 200."));
    chance_cards.push_back(new ChanceCard("Advance to FEUP", 2, "Advance to FEUP."));
    chance_cards.push_back(new ChanceCard("Advance to IPAM", 3, "Advance to IPAM. If you pass Go, collect ECTS 200."));
    chance_cards.push_back(new ChanceCard("Advance to the nearest Station", 4, "Advance token to the nearest Station and pay owner twice the rental to which he/she is otherwise entitled. If Station is unowned, you may buy it from the Bank."));
    chance_cards.push_back(new ChanceCard("Advance to the nearest Station", 5, "Advance token to the nearest Station and pay owner twice the rental to which he/she is otherwise entitled. If Station is unowned, you may buy it from the Bank."));
    chance_cards.push_back(new ChanceCard("Advance to the nearest Utility", 6, "Advance token to the nearest Utility and pay owner a total ten times amount thrown. If Utility is unowned, you may buy it from the Bank."));
    chance_cards.push_back(new ChanceCard("Bank pays you dividend", 7, "Bank pays you dividend of ECTS 50."));
    chance_cards.push_back(new ChanceCard("Get out of Praxis free", 8, "Get out of Praxis free. This card may be kept until needed or sold."));
    chance_cards.push_back(new ChanceCard("Go back 3 spaces", 9, "Go back 3 spaces."));
    chance_cards.push_back(new ChanceCard("Go to Praxis", 10, "Go directly to Praxis. Do not pass Go, do not collect ECTS 200."));
    chance_cards.push_back(new ChanceCard("Make general repairs on all your property", 11, "Make general repairs on all your property. For each house pay ECTS 25. For each hotel ECTS 100."));
    chance_cards.push_back(new ChanceCard("Pay transportation fee of ECTS 15", 12, "Pay transportation fee of ECTS 15."));
    chance_cards.push_back(new ChanceCard("Take a trip to Trindade", 13, "Take a trip to Trindade. If you pass Go, collect ECTS 200."));
    chance_cards.push_back(new ChanceCard("You have been elected President of the Student Association", 14, "You have been elected President of the Student Association. Pay each player ECTS 50."));
    chance_cards.push_back(new ChanceCard("Your student loan matures", 15, "Your building loan matures. Collect ECTS 150."));

    // Community Chest Cards  
    community_chest_cards.push_back(new CommunityChestCard("Advance to Go", 0, "Advance to Go. Collect ECTS 200."));
    community_chest_cards.push_back(new CommunityChestCard("Bank error in your favor", 1, "Bank error in your favor. Collect ECTS 200."));
    community_chest_cards.push_back(new CommunityChestCard("School material fee", 2, "School material fee. Pay ECTS 50."));
    community_chest_cards.push_back(new CommunityChestCard("Sale of stock", 3, "From sale of stock you get ECTS 50."));
    community_chest_cards.push_back(new CommunityChestCard("Get out of Praxis free", 4, "Get out of Praxis free. This card may be kept until needed or sold."));
    community_chest_cards.push_back(new CommunityChestCard("Go to Praxis", 5, "Go to Praxis. Go directly to Praxis. Do not pass Go, do not collect ECTS 200."));
    community_chest_cards.push_back(new CommunityChestCard("Scholarship Fund matures", 6, "Scholarship Fund matures. Receive ECTS 100."));
    community_chest_cards.push_back(new CommunityChestCard("Tuition fee refund", 7, "Tuition fee refund. Collect ECTS 20."));
    community_chest_cards.push_back(new CommunityChestCard("It is your graduation day", 8, "It is your graduation day. Collect ECTS 10 from every player."));
    community_chest_cards.push_back(new CommunityChestCard("Life insurance matures", 9, "Life insurance matures. Collect ECTS 100."));
    community_chest_cards.push_back(new CommunityChestCard("Pay hospital fees of ECTS 100", 10, "Pay hospital fees of ECTS 100."));
    community_chest_cards.push_back(new CommunityChestCard("Pay school insurance fees of ECTS 50", 11, "Pay school insurance fees of ECTS 50."));
    community_chest_cards.push_back(new CommunityChestCard("Receive ECTS 25 consultancy fee", 12, "Receive ECTS 25 consultancy fee."));
    community_chest_cards.push_back(new CommunityChestCard("You are assessed for street repairs", 13, "You are assessed for street repairs. Pay ECTS 40 per house and ECTS 115 per hotel you own."));
    community_chest_cards.push_back(new CommunityChestCard("You have won second prize in a spelling bee contest", 14, "You have won second prize in a spelling bee contest. Collect ECTS 10."));
    community_chest_cards.push_back(new CommunityChestCard("You inherit ECTS 100", 15, "You inherit ECTS 100."));
    
}

// function print the board
void Board::print_board(){
    for (size_t i = 0; i < positions.size(); i++){
        if (i == 11 || i == 21 || i == 31)
        {
            std::cout<<std::endl;
        }
        if (positions[i]->get_property_type() == GO)
        {
            std::cout<<"GO ";
        }
        if (positions[i]->get_property_type() == FACULTY)
        {
            std::cout<<positions[i]->get_facul()->get_name()<<" ";
        }
        if (positions[i]->get_property_type() == STATION)
        {
            std::cout<<positions[i]->get_station()->get_name()<< " ";
        }
        if (positions[i]->get_property_type() == UTILITY)
        {
            std::cout<<positions[i]->get_util()->get_name()<< " ";
        }
        if (positions[i]->get_property_type() == JAIL)
        {
            std::cout<<"JAIL ";
        }
        if (positions[i]->get_property_type() == GO_TO_JAIL)
        {
            std::cout<<"GO_TO_JAIL ";
        }
        if (positions[i]->get_property_type() == FREE_PARKING)
        {
            std::cout<<"FREE_PARKING ";
        }
        if (positions[i]->get_property_type() == TAX)
        {
            std::cout<<"TAX ";
        }
        if (positions[i]->get_property_type()==CHANCE)
        {
            std::cout<<"CHANCE ";
        }
        if (positions[i]->get_property_type() == COMMUNITY_CHEST)
        {
            std::cout<<"COMMUNITY_CHEST ";
        }     
    }
    std::cout<<std::endl;
    
}

Property* Board::get_property(int position){
    //std::cout<<"Entered get property"<<std::endl;
    return positions[position];
}

void Board::check_properties(Player* player){
    for (int i = 0; i < 40; i++)
    {
        if (positions[i]->get_property_type() == FACULTY || positions[i]->get_property_type() == STATION || positions[i]->get_property_type() == UTILITY)
        {

            if (positions[i]->get_property_owner() == player)
            {
               std::cout<<"----------------------------------------"<<std::endl;
               positions[i]->print_property();
               
            }
        }
    }
    std::cout<<"----------------------------------------"<<std::endl;
}

std::vector<int> Board::check_prop_improve(Player *Player){
    std::vector<int> prop;
    int flag=0;
    for (int i = 0; i < 40; i++)
    {
        if (positions[i]->get_property_type() == FACULTY)
        {
            if (positions[i]->get_property_owner() == Player)
            {
                if(flag==0){
                    std::cout<<"-----------------------------------------------------------------------------------------"<<std::endl;
                    flag=1;
                    std::cout<<"|\tPROPERTY\t|\tID\t|\tHouse Price\t|\tNº of houses\t|"<<std::endl;
                    std::cout<<"-----------------------------------------------------------------------------------------"<<std::endl;
                }
                if (check_if_can_build(Player, i)){
                    prop.push_back(positions[i]->get_id());
                    std::cout<<"|\t"<<positions[i]->get_facul()->get_name()<<"\t\t|\t"<<positions[i]->get_id()<<"\t|\t"<<positions[i]->get_facul()->get_build_house_price()<<"\t\t|\t"<<positions[i]->get_facul()->get_level()<<"\t\t|"<<std::endl;

                }
                
                
            }
        }
    }
    std::cout<<"-----------------------------------------------------------------------------------------"<<std::endl;
    return prop;
}

void Board::mortgage_prop(Player *Player, int id){
    positions[id]->change_mortgage_status();
    Player->give_money(positions[id]->get_mortgage_price());
}

std::vector<int> Board::check_prop_mortgage(Player *Player){
    int flag=0;
    std::vector<int> prop;

    for (int i = 0; i < 40; i++)
    {
        if (positions[i]->get_property_type() == FACULTY || positions[i]->get_property_type() == STATION || positions[i]->get_property_type() == UTILITY)
        {
            if (positions[i]->get_property_owner() == Player && !positions[i]->get_if_mortgaged())
            {
                if(flag==0){
                    std::cout<<"-----------------------------------------------------------------"<<std::endl;
                    flag=1;
                    std::cout<<"|\tPROPERTY\t|\tID\t|\tMortgage Price\t|"<<std::endl;
                    std::cout<<"-----------------------------------------------------------------"<<std::endl;
                }
                if (positions[i]->get_property_type()==FACULTY || positions[i]->get_property_type()==UTILITY)
                    std::cout<<"|\t"<<positions[i]->get_property_name()<<"\t\t|\t"<<positions[i]->get_id()<<"\t|\t"<<positions[i]->get_mortgage_price()<<"\t\t|"<<std::endl;
                else
                    std::cout<<"|\t"<<positions[i]->get_property_name()<<"\t|\t"<<positions[i]->get_id()<<"\t|\t"<<positions[i]->get_mortgage_price()<<"\t\t|"<<std::endl;
                
                prop.push_back(positions[i]->get_id());
            }
        }
    }
    std::cout<<"-----------------------------------------------------------------"<<std::endl;
    return prop;
}

void Board::unmortgage_prop(Player *Player, int id){
    positions[id]->change_mortgage_status();
    if (Player->check_balance() < positions[id]->get_mortgage_price())
    {
        std::cout<<"You don't have enough money to unmortgage this property"<<std::endl;
    }
    else
        Player->take_money(positions[id]->get_mortgage_price());
}

std::vector<int> Board::check_prop_unmortgage(Player *Player){
    int flag=0;
    std::vector<int> prop;

    for (int i = 0; i < 40; i++)
    {
        if (positions[i]->get_property_type() == FACULTY || positions[i]->get_property_type() == STATION || positions[i]->get_property_type() == UTILITY)
        {
            if (positions[i]->get_property_owner() == Player && positions[i]->get_if_mortgaged())
            {
                if(flag==0){
                    std::cout<<"-----------------------------------------------------------------"<<std::endl;
                    flag=1;
                    std::cout<<"|\tPROPERTY\t|\tID\t|\tMortgage Price\t|"<<std::endl;
                    std::cout<<"-----------------------------------------------------------------"<<std::endl;
                }
                if (positions[i]->get_property_type()==FACULTY || positions[i]->get_property_type()==UTILITY)
                    std::cout<<"|\t"<<positions[i]->get_property_name()<<"\t\t|\t"<<positions[i]->get_id()<<"\t|\t"<<positions[i]->get_mortgage_price()<<"\t\t|"<<std::endl;
                else
                    std::cout<<"|\t"<<positions[i]->get_property_name()<<"\t|\t"<<positions[i]->get_id()<<"\t|\t"<<positions[i]->get_mortgage_price()<<"\t\t|"<<std::endl;
                                prop.push_back(positions[i]->get_id());
            }
        }
    }
    std::cout<<"-----------------------------------------------------------------"<<std::endl;
    return prop;
}

//check if a Player *Player can build a house in a property with id, if have all the properties of the that color
bool Board::check_if_can_build(Player *Player, int id){
    int count=1;
    int color=positions[id]->get_facul()->get_color();
    
    if(color==BROWN || color==DARKBLUE)
    {
        for (int i = 1; i <= 2; i++)
        {
            if(id-i>0 && id-i<40){
            if(positions[id-i]->get_property_type()==FACULTY && Player==positions[id-i]->get_property_owner())
                {
                    if (positions[id-i]->get_facul()->get_color()==color)
                        count++;
                }
            }
            if(id+i>0 && id+i<40){
                if(positions[id+i]->get_property_type()==FACULTY && Player==positions[id+i]->get_property_owner())
                {
                    if (positions[id+i]->get_facul()->get_color()==color)
                        count++;
                }
                if (count==2)
                {
                    return true;
                }
            }
        }

    }
    if (color==LIGHTBLUE || color==PINK || color==ORANGE || color==RED || color==YELLOW || color==GREEN)
    {
        for (int i = 1; i <= 3; i++)
        {
            if(id-i>0 && id-i<40){
                if(positions[id-i]->get_property_type()==FACULTY && Player==positions[id-i]->get_property_owner() && id-i>0 && id-i<40)
                {
                    if (positions[id-i]->get_facul()->get_color()==color)
                        count++;
                }
            }
            if(id+i>0 && id+i<40){
                if(positions[id+i]->get_property_type()==FACULTY && Player==positions[id+i]->get_property_owner() && id+i>0 && id+i<40 )
                {
                    if (positions[id+i]->get_facul()->get_color()==color)
                        count++;
                }
            }
            if (count==3)
            {
                return true;
            }
        }
    }
    return false;
}


Property* Board::get_property_by_name(std::string name){
    for (int i = 0; i < 40; i++)
    {
        if (positions[i]->get_property_name()==name)
        {
            return positions[i];
        }
    }
    return NULL;
}
