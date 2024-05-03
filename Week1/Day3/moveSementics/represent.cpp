/*
    represnt "state" of "something"
*/

class TrainingSession{
/* 
    _duration (in hours) : int
    _studentCOunt : unsigned int
    _trainerName : string
    _sessionTopic : string
    _date : DateTime
*/
};//represent state

class ID{
    /* 
        _country :COUNTRY
        _year : 24
        _month : 01
        _track_level : LEVEL
        _batch_no : 01
        _batch_track : TRACK
        _location : P
     */
};

class TrainingBatch{
    /* 
        _id : ID
        _strength : unsigned int
        _trainer : Trainer ------------------PERSON
        _pmt_coordinator : Coordinator-------PERSON
        _schedule : Schedule
        _talents : Container<Talent>---------PERSON
    */
};


/* 
    Pointer ka state representation
            ---> Smart Pointer
    Reference ka state 
            ---> reference_wrapper
    Thread (set of instruction)
            ---  std ::async
    Semaphore ka state
            ---  lock_gaurd
            ---> unique_lock
    Union ka state representation
            ---> std::variant
 */