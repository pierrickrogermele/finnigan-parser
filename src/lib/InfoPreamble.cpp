#include "SequencerRow.hpp"
#include "InjectionData.hpp"
#include "PString.hpp"
#include "Integer.hpp"
#include "InfoPreamble.hpp"
#include "names.hpp"

using namespace org::openscience::ms::finnigan;

/////////////////////
// DEFINE CHILDREN //
/////////////////////

void InfoPreamble::define_children() {
	if (this->children.empty()) {
	    //Children common to all the version.
        this->add_child(FEN_METHOD_FILE_PRESENT,  new Integer<uint32_t>());
        this->add_child(FEN_YEAR,                 new Integer<uint16_t>());
		this->add_child(FEN_MONTH,                new Integer<uint16_t>());
		this->add_child(FEN_WEEKDAY,              new Integer<uint16_t>());
		this->add_child(FEN_DAY,                  new Integer<uint16_t>());
		this->add_child(FEN_HOUR,                 new Integer<uint16_t>());
		this->add_child(FEN_MINUTE,               new Integer<uint16_t>());
		this->add_child(FEN_SECOND,               new Integer<uint16_t>());
		this->add_child(FEN_MILLISECOND,          new Integer<uint16_t>());

		//Version superior to 57.
        if(this->get_version()>=57){
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(FEN_DATA_ADRESS,              new Integer<uint32_t>());
            this->add_child(FEN_N_CONTROLLERS,            new Integer<uint32_t>());
            this->add_child(FEN_N_CONTROLLERS2,           new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            this->add_child(                              new Integer<uint32_t>());
            //The number of cotrollers is read.
            if(this->get_version()<64){
                int nController=this->get_child(FEN_N_CONTROLLERS)->get_int();
                for(int i=0;i<nController;i++){

                	// Read address
                    std::wstring run_header_address = FEN_RUN_HEADER_ADDRESS L"_" + std::to_wstring(i);
                    this->add_child(run_header_address,    new Integer<uint32_t>());
                    this->add_child(                       new Integer<uint32_t>());
                    this->add_child(                       new Integer<uint32_t>());
                }
            }
            //Adding the correct number of child depending of the version.
            this->add_child(FEN_N_CONTROLLERS2,           new Integer<uint32_t>());

            //Getting the good version number.

            if(this->get_version()<64){

            }
        }

	}
}

