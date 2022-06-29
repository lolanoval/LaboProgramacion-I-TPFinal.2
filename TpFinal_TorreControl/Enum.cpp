#include "Enum.h"

string EstadoToString(eEstado estado)
{
	switch (estado)
	{
	case eEstado::Aterrizando:
		return "Aterrizando";
		break;
	case eEstado::Despegando:
		return "Despegando";
		break;
	case eEstado::Volando:
		return "Volando";
		break;
	case eEstado::enEspera:
		return "En espera...";
		break;
	default:
		return "En espera...";
		break;
	}
}

string ModeloToString(eModelo modelo)
{
	switch (modelo)
	{
	case eModelo::A1:
		return "A1";
		break;
	case eModelo::B2:
		return "B2";
		break;
	default:
		return "";
		break;
	}
}
