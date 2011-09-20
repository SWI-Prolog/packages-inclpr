/*

    Part of INCLP(R)

    Author:        Leslie De Koninck
    E-mail:        Leslie.DeKoninck@cs.kuleuven.be
    WWW:           http://www.swi-prolog.org
    Copyright (C): 2006, K.U. Leuven

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation; either version 2
    of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    As a special exception, if you link this library with other files,
    compiled with a Free Software compiler, to produce an executable, this
    library does not by itself cause the resulting executable to be covered
    by the GNU General Public License. This exception does not however
    invalidate any other reasons why the executable file might be covered by
    the GNU General Public License.
*/

% We need this to run Prolog from the development tree, loading .ddl
% files from the installed system

:- if(current_prolog_flag(windows,true)).
:- multifile user:file_search_path/2.
user:file_search_path(foreign, swi(bin)).
:- endif.

compile :-
	qcompile(inclpr/inclpr_core),
	qcompile(inclpr),
	qcompile(inclpr/inclpr_consistency),
	qcompile(inclpr/inclpr_interval_arithmetic),
	qcompile(inclpr/inclpr_inversion),
	qcompile(inclpr/inclpr_natural_interval_extension),
	qcompile(inclpr/inclpr_newton),
	qcompile(inclpr/inclpr_ordering),
	qcompile(inclpr/inclpr_symbolic_processing).
