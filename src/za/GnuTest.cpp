
#if 0
void PIDAssign(uint16_t iRecvPno, PID& refOut)
{
    SELF_PID(&refOut);
#ifdef __GNUC__
#  pragma GCC diagnostic push
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wsign-conversion"
#endif
    refOut.pno = iRecvPno;
#ifdef __GNUC__
#  pragma GCC diagnostic pop
#endif
}

#endif
