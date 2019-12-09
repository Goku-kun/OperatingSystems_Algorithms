#!/bin/bash

read -p 'Enter a number: ' size
vpos=0
while [[ $vpos -le $(( $size * 2 )) ]]
do
        hpos=0
        while [[ $hpos -le $(( $size * 2 )) ]]
        do
                if [[ $vpos -le $size ]]
                then
                        if ( [ $hpos -lt $(( $size - $vpos )) ] && [ $hpos -lt $size ] ) || ( [ $hpos -gt $(( $size + $vpos )) ] && [ $hpos -gt $size ] )
                        then
                                echo -n ' '
                        else
                                echo -n '*'
                        fi

                else
                        if ( [ $hpos -lt $(( $vpos - $size ))  ] && [ $hpos -lt $size ] ) || ( [ $hpos -gt $(( 3 * $size - $vpos )) ] && [ $hpos -gt $size  ] )
                        then
                                echo -n ' '
                        else
                                echo -n '*'
                        fi

                fi

                hpos=$((hpos + 1))

        done
        echo ''
        vpos=$((vpos + 1))
done
