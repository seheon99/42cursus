/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyu <seyu@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 23:07:20 by seyu              #+#    #+#             */
/*   Updated: 2021/04/11 00:54:42 by seyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <cstdlib>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() throw()
		: Form("Shrubbery Creation Form", 145, 137),
		_target(std::string())
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const& target)
		: Form("Shrubbery Creation Form", 145, 137),
		_target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
		: Form("Shrubbery Creation Form", 145, 137),
		_target(other._target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{}

const char*
	ShrubberyCreationForm::CannotOpenFileException::what() const throw()
{
	return ("Cannot open the target file.");
}

ShrubberyCreationForm&
	ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other) throw()
{
	Form::operator=(other);
	return (*this);
}

bool
	ShrubberyCreationForm::execute(const Bureaucrat& executer) const
{
	Form::execute(executer);

	std::ofstream	out(_target + "_shrubbery");
	if (out.is_open())
	{
		out << _trees[std::rand() % 4];
		out.close();
		return (true);
	}
	else
		throw CannotOpenFileException();
}


const std::string	ShrubberyCreationForm::_trees[4] = {
	"         . . .\n" \
	"       .        .  .     ..    .\n" \
	"    .                 .         .  .\n" \
	"                    .\n" \
	"                   .                ..\n" \
	"   .          .            .              .\n" \
	"   .            '.,        .               .\n" \
	"   .              'b      *\n" \
	"    .              '$    #.                ..\n" \
	"   .    .           $:   #:               .\n" \
	" ..      .  ..      *#  @):        .   . .\n" \
	"              .     :@,@):   ,.**:'   .\n" \
	"  .      .,         :@@*: ..**'      .   .\n" \
	"           '#o.    .:(@'.@*\"'  .\n" \
	"   .  .       'bq,..:,@@*'   ,*      .  .\n" \
	"              ,p$q8,:@)'  .p*'      .\n" \
	"       .     '  . '@@Pp@@*'    .  .\n" \
	"        .  . ..    Y7'.'     .  .\n" \
	"                  :@):.\n" \
	"                 .:@:'.\n" \
	"               .::(@:.      -Sam Blumenstein-\n",
	\
	"         - - -\n" \
	"       -        -  -     --    -\n" \
	"    -                 -         -  -\n" \
	"                    -\n" \
	"                   -                --\n" \
	"   -          -            -              -\n" \
	"   -            '-,        -               -\n" \
	"   -              'b      *\n" \
	"    -              '$    #-                --\n" \
	"   -    -           $:   #:               -\n" \
	" --      -  --      *#  @):        -   - -\n" \
	"              -     :@,@):   ,-**:'   -\n" \
	"  -      -,         :@@*: --**'      -   -\n" \
	"           '#o-    -:(@'-@*\"'  -\n" \
	"   -  -       'bq,--:,@@*'   ,*      -  -\n" \
	"              ,p$q8,:@)'  -p*'      -\n" \
	"       -     '  - '@@Pp@@*'    -  -\n" \
	"        -  - --    Y7'.'     -  -\n" \
	"                  :@):.\n" \
	"                 .:@:'.\n" \
	"               .::(@:.      -Sam Blumenstein-\n",
	\
	"         / / /\n" \
	"       /        /  /     //    /\n" \
	"    /                 /         /  /\n" \
	"                    /\n" \
	"                   /                //\n" \
	"   /          /            /              /\n" \
	"   /            '/,        /               /\n" \
	"   /              'b      *\n" \
	"    /              '$    //                //\n" \
	"   /    /           $:   /:               /\n" \
	" //      /  //      */  @):        /   / /\n" \
	"              /     :@,@):   ,/**:'   /\n" \
	"  /      /,         :@@*: //**'      /   /\n" \
	"           '/o/    /:(@'/@*\"'  /\n" \
	"   /  /       'bq,//:,@@*'   ,*      /  /\n" \
	"              ,p$q8,:@)'  /p*'      /\n" \
	"       /     '  / '@@Pp@@*'    /  /\n" \
	"        /  / //    Y7'.'     /  /\n" \
	"                  :@):.\n" \
	"                 .:@:'.\n" \
	"               .::(@:.      -Sam Blumenstein-\n",
	\
	"         ; ; ;\n" \
	"       ;        ;  ;     ;;    ;\n" \
	"    ;                 ;         ;  ;\n" \
	"                    ;\n" \
	"                   ;                ;;\n" \
	"   ;          ;            ;              ;\n" \
	"   ;            ';,        ;               ;\n" \
	"   ;              'b      *\n" \
	"    ;              '$    ;;                ;;\n" \
	"   ;    ;           $:   ;:               ;\n" \
	" ;;      ;  ;;      *;  @):        ;   ; ;\n" \
	"              ;     :@,@):   ,;**:'   ;\n" \
	"  ;      ;,         :@@*: ;;**'      ;   ;\n" \
	"           ';o;    ;:(@';@*\"'  ;\n" \
	"   ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n" \
	"              ,p$q8,:@)'  ;p*'      ;\n" \
	"       ;     '  ; '@@Pp@@*'    ;  ;\n" \
	"        ;  ; ;;    Y7'.'     ;  ;\n" \
	"                  :@):.\n" \
	"                 .:@:'.\n" \
	"               .::(@:.      -Sam Blumenstein-\n"
};
